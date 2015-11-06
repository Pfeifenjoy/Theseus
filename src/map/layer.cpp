#include "layer.hpp"
#include <cassert>
#include <time.h>
#include "../gameobjects/brick.hpp"
#include "../gameobjects/floor.hpp"
#include <math.h>

using namespace theseus::map;
using namespace theseus::gameobjects;
using namespace std;

Layer::Layer(unique_ptr<LevelDescription> description) {
	srand(time(NULL));

	auto dimensions = description->getDimensions();
	int width = (int) (dimensions.x / Brick::WIDTH);
	int height = (int) (dimensions.y / Brick::HEIGHT);

	this->layer = vector<vector<FieldStatus> > (width, vector<FieldStatus> (height, FREE));

	this->addWall(0, 0, SOUTH, height);
	this->addWall(1, 0, EAST, width);
	this->addWall(1, height - 1, EAST, width - 1);
	this->addWall(width - 1, 1, SOUTH, height - 2);
	this->populateRoomObjects(description->getRooms());

	sf::Vector2f minSizeF = description->getMinRoomSize();
	sf::Vector2f maxSizeF = description->getMaxRoomSize();
	sf::Vector2<int> minSize(floor(minSizeF.x / Brick::WIDTH), floor(minSizeF.y / Brick::HEIGHT));
	sf::Vector2<int> maxSize(floor(maxSizeF.x / Brick::WIDTH), floor(maxSizeF.y / Brick::HEIGHT));
	this->fillWithRooms(minSize, maxSize, description->getMaxAmountOfStandardRooms());
	fillWithWalls(3, 20, 16, 200);
	fillWithWalls(3, 20, 8, 200);
	fillWithWalls(3, 20, 4, 200);
	fillWithWalls(3, 20, 2, 200);
	this->generateGameObjectField();
	this->freeRestrictions();
	this->populateGameObjects(description->getFreeObjects());
}

void Layer::fillWithRooms(sf::Vector2<int> minSize, sf::Vector2<int> maxSize, int numRooms) {
	assert(numRooms > 0);
	assert(minSize.x > 0 && minSize.y > 0);
	assert(maxSize.x > minSize.x && maxSize.y > minSize.y);
	while(numRooms--) {
		int width = rand() % (maxSize.x - minSize.x) + minSize.x;
		int height = rand() % (maxSize.y - minSize.y) + minSize.y;
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
		if(status == VERTICAL_RESTRICTED || status == HORIZONTAL_RESTRICTED)
			this->memorizedCorridorFloors.push_back(sf::Vector2<int> (x, y));
		if(status != OCCUPIED) {
			switch(this->layer[x][y]) {
				case OCCUPIED: if(status == OCCUPIED) return realLength; break;
				case RESTRICTED: if(status == OCCUPIED) return realLength;
				case VERTICAL_RESTRICTED: if(status == HORIZONTAL_RESTRICTED)
											  {
												  layer[x][y] = RESTRICTED; break;
											  }
				case HORIZONTAL_RESTRICTED: if(status == VERTICAL_RESTRICTED)
												 {
													 layer[x][y] = RESTRICTED; break;
												 }

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
				setFloor(i, j, ROOM);
			}
		}
		this->addDoor(x, y, width, height);
		//sf::Vector2f position((x+1)*Brick::WIDTH, (y+1)*Brick::HEIGHT);
		//sf::Vector2f size((width - 1) * Brick::WIDTH, (height-1) * Brick::HEIGHT);
		//this->gameobjects.push_back(unique_ptr<Room> (new Room(position, size)));
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
	setFloor(x, y, ROOM);
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
			if(this->layer[i][j] == FREE) {
				this->setFloor(i, j, CORRIDOR);
			}
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
	for(auto position : this->memorizedCorridorFloors) {
		setFloor(position.x, position.y, CORRIDOR);
	}
}

void Layer::setFloor(int x, int y, FloorType type) {
	int extraWidthLeft = layer[x-1][y] == OCCUPIED ? 6 : 0;
	int extraWidthRight = layer[x+1][y] == OCCUPIED ? 6 : 0;
	sf::Vector2f position(Brick::WIDTH * x - extraWidthLeft, Brick::HEIGHT * y);
	sf::Vector2f size(Brick::WIDTH + extraWidthRight + extraWidthLeft, Brick::HEIGHT);
	unique_ptr<Floor> floor(new Floor(position, size, type));
	this->gameobjects.push_back(move(floor));
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

void Layer::freeRestrictions() {
	for(auto& column: this->layer) {
		for(auto& field: column) {
			if(field != OCCUPIED && field != FREE) {
				field = FREE;
			}
		}
	}
}

vector<sf::Vector2<int> > Layer::getPossiblePlaces(int width, int height) {
	vector<sf::Vector2<int> > places;
	int i, j;
	for(i = 0; i < (int)this->layer.size() - width; i++) {
		for(j = 0; j < (int)this->layer[i].size() - height; j++) {
			if(checkField(i, j, width, height))
				places.push_back(sf::Vector2<int> (i, j));
		}
	}
	return places;
}

void Layer::occupy(int x, int y, int width, int height) {
	int i, j;
	for(i = x; i < x + width; i++) {
		for(j = y; j < y + height; j++) {
			this->layer[i][j] = RESTRICTED;
		}
	}
}

void Layer::populateGameObjects(vector<unique_ptr<Positionable> > freeGameObjects) {
	for(auto& object : freeGameObjects) {
		sf::Vector2f topLeft = object->getCollisionAreaTopLeft();
		sf::Vector2f rightBottom = object->getCollisionAreaBottomRight();
		int width = (int) ceil((rightBottom.x - topLeft.x) / Brick::WIDTH);
		int height = (int) ceil((rightBottom.y - topLeft.y) / Brick::HEIGHT);
		auto possiblePlaces = this->getPossiblePlaces(width, height);
		auto field = rand() % possiblePlaces.size();
		auto coords = possiblePlaces[field];
		sf::Vector2f position(coords.x * Brick::WIDTH, coords.y * Brick::HEIGHT);
		object->setPosition(position);
		this->gameobjects.push_back(move(object));
		this->occupy(coords.x, coords.y, width, height);
	}
}

void Layer::populateRoomObjects(vector<unique_ptr<RoomDescription> > rooms) {
	for(auto& room: rooms) {
		int width = ceil(room->getWidth() / Brick::WIDTH);
		int height = ceil(room->getHeight() / Brick::HEIGHT);
		auto possiblePlaces = getPossiblePlaces(width + 1, height + 1);
		if(possiblePlaces.size() == 0) continue;
		auto startField = rand() % possiblePlaces.size();
		auto position = possiblePlaces[startField];
		addRoom(position.x + 1, position.y + 1, width, height);
	}
}

vector<unique_ptr<theseus::engine::GameObject> > Layer::getGameObjects() {
	return move(this->gameobjects);
}

unique_ptr<theseus::engine::Scene> Layer::toScene() {
	unique_ptr<theseus::engine::Scene> scene(new theseus::engine::Scene());
	auto objects = this->getGameObjects();
	for(auto& object: objects) {
		scene->addGameObject(move(object));
	}
	return scene;
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
