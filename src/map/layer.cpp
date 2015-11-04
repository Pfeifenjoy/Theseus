#include "layer.hpp"
#include <cassert>
#include <time.h>
#include "../gameobjects/brick.hpp"

using namespace theseus::map;
using namespace theseus::gameobjects;
using namespace std;

Layer::Layer(int width, int height) {
	srand(time(NULL));
	this->layer = vector<vector<FieldStatus> > (width, vector<FieldStatus> (height, FREE));

	this->addWall(0, 0, SOUTH, height);
	this->addWall(1, 0, EAST, width);
	this->addWall(1, height - 1, EAST, width - 1);
	this->addWall(width - 1, 1, SOUTH, height - 2);
	this->fillWithRooms(7, 10, rand() % 20 + 1);
	fillWithWalls(3, 20, 16, 200);
	fillWithWalls(3, 20, 8, 200);
	fillWithWalls(3, 20, 4, 200);
	fillWithWalls(3, 20, 2, 200);
	this->generateGameObjectField();
}

void Layer::fillWithRooms(int minSize, int maxSize, int numRooms) {
	assert(numRooms > 0);
	assert(minSize > 0);
	assert(maxSize > minSize);
	while(numRooms--) {
		int width = rand() % (maxSize - minSize) + minSize;
		int height = rand() % (maxSize - minSize) + minSize;
		int x = (int) this->layer.size() - width < 0 ? 0 :
				rand() % (int) (this->layer.size() - width);
        int y = (int) this->layer[x].size() - height < 0 ? 0 :
				rand() % (int) (this->layer[x].size() - height);
		if(x < 2) x = 2;
		if(y < 2) y = 2;
		if(x > (int) this->layer.size() - 2 - width) x = (int) this->layer.size() - 2 -width;
		if(y > (int) this->layer[x].size() - 2 - height) y = (int) this->layer[x].size() - 2 - height;
		this->addRoom(x, y, width, height);
	}
}


bool Layer::checkField(int x, int y, int width /* = 1 */, int height /* = 1 */) {
	assert(width > 0);
	assert(height > 0);
	assert(x >= 0);
	assert(x + width < (int) this->layer.size());
	assert(y >= 0);
	assert(y + height < (int) this->layer[x].size());
	int i, j;
	for(i = x; i < x + width; i++) {
		for(j = y; j < y + height; j++) {
			switch(layer[i][j]) {
				case FREE: break;
				case VERTICAL_RESTRICTED:
							   if(i == 0 || i == x + width - 1) return false;
							   break;
				case HORIZONTAL_RESTRICTED:
							   if(j == 0 || j == y + height - 1) return false;
							   break;
				case RESTRICTED:
				case OCCUPIED: return false;
			}
		}
	}

	return true;
}

int Layer::drawLine(int x, int y, Direction direction, int length, FieldStatus status) {
	int realLength = 0;
	while(length--) {
		if(x < 0 || y < 0 || x >= (int) layer.size() || y >= (int) this->layer[x].size())
		   	return realLength;
		if(status != OCCUPIED) {
			switch(this->layer[x][y]) {
				case OCCUPIED: if(status == OCCUPIED) return realLength; break;
				case RESTRICTED: if(status == OCCUPIED) return realLength;
				case VERTICAL_RESTRICTED: if(status == HORIZONTAL_RESTRICTED)
											  { layer[x][y] = RESTRICTED; break; }
				case HORIZONTAL_RESTRICTED: if(status == VERTICAL_RESTRICTED)
												 { layer[x][y] = RESTRICTED; break; }
				case FREE: layer[x][y] = status;
			}
		} else {
			if (layer[x][y] == OCCUPIED || layer[x][y] == RESTRICTED || (layer[x][y] != FREE && realLength == 0)){
				return realLength;
			}
			layer[x][y] = status;
		}
		realLength++;
		switch(direction) {
			case NORTH: y--; break;
			case WEST: x--; break;
			case SOUTH: y++; break;
			case EAST: x++; break;
		}
	}
	return realLength;
}

void Layer::addRoom(int x, int y, int width, int height) {
	if(checkField(x, y, width, height)){
		addWall(x, y, EAST, width);
		addWall(x, y + 1, SOUTH, height - 1);
		addWall(x + width - 1, y + 1, SOUTH, height - 1);
		addWall(x + 1, y + height - 1, EAST, width - 1);
		drawLine(x - 1, y - 1, EAST, width + 2, VERTICAL_RESTRICTED);
		drawLine(x - 1, y - 1, SOUTH, height + 2, HORIZONTAL_RESTRICTED);
		drawLine(x - 1, y + height, EAST, width + 2, VERTICAL_RESTRICTED);
		drawLine(x + width , y - 1, SOUTH, height + 2, HORIZONTAL_RESTRICTED);
		int i, j;
		for(i = x + 1; i < x + width -1; i++) {
			for(j = y + 1; j < y + height -1; j++) {
				layer[i][j] = RESTRICTED;
			}
		}
		this->addDoor(x, y, width, height);
		sf::Vector2f position((x+1)*Brick::WIDTH, (y+1)*Brick::HEIGHT);
		sf::Vector2f size((width - 1) * Brick::WIDTH, (height-1) * Brick::HEIGHT);
		this->gameobjects.push_back(unique_ptr<Room> (new Room(position, size)));
	}
}

void Layer::addDoor(int x, int y, int width, int height) {
	int side = rand() % 4;
	int offset = rand() % ((side % 2 ? height : width) - 2) + 1;
	//int offset = (side % 2 ? height : width) - 2;
	switch(side) {
		case 0: x += offset; break;
		case 1: y += offset; x += width - 1; break;
		case 2: x += offset; y += height - 1; break;
		case 3: y += offset; break;
	}
	this->layer[x][y] = RESTRICTED;
	switch(side) {
		case 0: y--; break;
		case 1: x++; break;
		case 2: y++; break;
		case 3: x--; break;
	}
	this->layer[x][y] = RESTRICTED;
}

void Layer::fillWithWalls(int minLength, int maxLength, int granularity, int numWalls) {
	assert(numWalls >= 0);
	assert(granularity % 2 == 0);
	assert(minLength > 0);
	assert(maxLength > 0 && maxLength > minLength);
    while(numWalls--) {
        int x = granularity * (rand() % ((this->layer.size() - 2) / granularity));
        int y = granularity * (rand() % ((this->layer[x].size() - 2) / granularity));
        Direction dir = Direction(rand() % 4);
        int length = granularity * ((rand() % (maxLength -minLength)) + minLength) ;
        this->addWall(x, y, dir, length);
    }
}

void Layer::generateGameObjectField() {
	int i, j;
	short k;
	for(i = 0; i < (int) layer.size() ; i++) {
		for(j = 0; j < (int) layer[i].size() ; j++) {
			if(this->layer[i][j] != OCCUPIED) continue;
			k = 0;
			if(j-1 >= 0)
				k += this->layer[i][j - 1] == OCCUPIED ? 2 : 0;
			if(i + 1 < (int) layer.size())
				k += this->layer[i + 1][j] == OCCUPIED ? 4 : 0;
			if(j + 1 < (int) layer[i].size())
				k += this->layer[i][j + 1] == OCCUPIED ? 8 : 0;
			if(i - 1 >= 0)
				k += this->layer[i - 1][j] == OCCUPIED ? 16 : 0;
			BrickType type = HORIZONAL;
			switch(k) {
				case 2: type = BOTTOM_END; break;
				case 4: type = LEFT_END; break;
				case 8: type = TOP_END; break;
				case 16: type = RIGHT_END; break;
				case 10: type = VERTICAL; break;
				case 20: type = HORIZONAL; break;
				case 6: type = EDGE_LEFT_BOTTOM; break;
				case 12: type = EDGE_LEFT_TOP; break;
				case 24: type = EDGE_RIGHT_TOP; break;
				case 18: type = EDGE_RIGHT_BOTTOM; break;
				case 22: type = T_UPSIDEDOWN_CROSS; break;
				case 14: type = LEFT_MIDDLE; break;
				case 28: type = T_CROSS; break;
				case 26: type = RIGHT_MIDDLE; break;
				case 30: type = CROSS; break;
			}
			unique_ptr<Brick > brick(new Brick(type, i, j));
			this->gameobjects.push_back(move(brick));
		}
	}
}

void Layer::addWall(int x, int y, Direction direction, int length) {
	assert(length > 0);
	assert(x >= 0);
	assert(x < (int) this->layer.size());
	assert(y >= 0);
	assert(y < (int) this->layer[x].size());
	int realLength = drawLine(x, y, direction, length, OCCUPIED);
	if(realLength == 0) return;
}


vector<unique_ptr<theseus::engine::GameObject> > Layer::getGameObjects() {
	return move(this->gameobjects);
}

ostream& theseus::map::operator<<(ostream& os, const Layer& layer) {
	int i = 0, j = 0;

	for(i = 0; i < (int) layer.layer[0].size(); i++) {
		for(j = 0; j < (int) layer.layer.size(); j++) {
			switch(layer.layer[j][i]) {
				case OCCUPIED: os <<"\x1B[33m"; break; //Yellow
				case FREE: os << "\x1B[34m"; break; //Blue
				case RESTRICTED: os << "\x1b[31m"; break; //Red
				case VERTICAL_RESTRICTED: os << "\x1b[32m"; break; //Green
				case HORIZONTAL_RESTRICTED: os << "\x1b[35m"; break; //Magenta
			}
			os << "\u2588";
		}
		os << endl;
	}
	os << "\x1B[0m";


	return os;
}
