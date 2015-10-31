/**
 * author Arwed Mett
 */
#include "Map.hpp"
#include <cassert>
#include <time.h>

using namespace theseus::map;
using namespace std;

/**
 * Initialize a squared map.
 * @param width {int}
 * @param height {int}
 */
Map::Map(int width, int height) {
	srand(time(NULL));
	this->map = vector<vector<FieldStatus> > (width, vector<FieldStatus> (height, FREE));

	//Print the frame
	this->addWall(0, 0, SOUTH, height);
	this->addWall(1, 0, EAST, width);
	this->addWall(1, height - 1, EAST, width - 1);
	this->addWall(width - 1, 1, SOUTH, height - 2);
	this->fillWithRooms(7, 10, 4);
	fillWithWalls(3, 20, 16, 200);
	fillWithWalls(3, 20, 8, 200);
	fillWithWalls(3, 20, 4, 200);
	fillWithWalls(3, 20, 2, 200);
}

void Map::fillWithRooms(int minSize, int maxSize, int numRooms) {
	assert(numRooms > 0);
	assert(minSize > 0);
	assert(maxSize > minSize);
	while(numRooms--) {
		int width = rand() % (maxSize - minSize) + minSize;
		int height = rand() % (maxSize - minSize) + minSize;
        int x = (int) this->map.size() - width < 0 ? 0 :
				rand() % (int) (this->map.size() - width);
        int y = (int) this->map[x].size() - height < 0 ? 0 :
				rand() % (int) (this->map[x].size() - height);
		this->addRoom(x, y, width, height);
	}
}


bool Map::checkField(int x, int y, int width /* = 1 */, int height /* = 1 */) {
	assert(width > 0);
	assert(height > 0);
	assert(x >= 0);
	assert(x + width < (int) this->map.size());
	assert(y >= 0);
	assert(y + height < (int) this->map[x].size());
	int i, j;
	for(i = x; i < x + width; i++) {
		for(j = y; j < y + height; j++) {
			switch(map[i][j]) {
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

int Map::drawLine(int x, int y, Direction direction, int length, FieldStatus status) {
	int realLength = 0;
	while(length--) {
		if(x < 0 || y < 0 || x >= (int) map.size() || y >= (int) this->map[x].size())
		   	return realLength;
		if(status != OCCUPIED) {
			switch(this->map[x][y]) {
				case OCCUPIED: if(status == OCCUPIED) return realLength; break;
				case RESTRICTED: if(status == OCCUPIED) return realLength;
				case VERTICAL_RESTRICTED: if(status == HORIZONTAL_RESTRICTED)
											  { map[x][y] = RESTRICTED; break; }
										  if(direction % 2 == 1) return realLength;
				case HORIZONTAL_RESTRICTED: if(status == VERTICAL_RESTRICTED)
												 { map[x][y] = RESTRICTED; break; }
											if(direction % 2 == 0) return realLength;
				case FREE: map[x][y] = status;
			}
		} else {
			if (map[x][y] == OCCUPIED || map[x][y] == RESTRICTED || (map[x][y] != FREE && realLength == 0)){
				return realLength;
			}
			map[x][y] = status;
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

void Map::addRoom(int x, int y, int width, int height) {
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
				map[i][j] = RESTRICTED;
			}
		}
		this->rooms.push_back(shared_ptr<Room> (new Room(x + 1, y + 1, width - 1, height - 1)));
	}
}

/**
 * Fill the map with random walls.
 * This generates a labyrinth.
 * @param minLength {int} Minimum length of a wall. This might not always happen.
 * @param maxLength {int} Maximum length of a wall.
 * @param granularity {int} Sets the space between the walls.
 * @param numWalls {int} Maximum amount of walls which will be generated.
 */
void Map::fillWithWalls(int minLength, int maxLength, int granularity, int numWalls) {
	assert(numWalls >= 0);
	assert(granularity % 2 == 0);
	assert(minLength > 0);
	assert(maxLength > 0 && maxLength > minLength);
    while(numWalls--) {
        int x = granularity * (rand() % ((this->map.size() - 2) / granularity));
        int y = granularity * (rand() % ((this->map[x].size() - 2) / granularity));
        Direction dir = Direction(rand() % 4);
        int length = granularity * ((rand() % (maxLength -minLength)) + minLength) ;
        this->addWall(x, y, dir, length);
    }
}

/**
 * This will try to add a Wall to the map, by a given length and position.
 * @param x {int} x Coordinate
 * @param y {int} y Coordinate
 * @param direction {theseus::map::Direction}
 * @param length {int} maximal Length of the wall.
 */
void Map::addWall(int x, int y, Direction direction, int length) {
	assert(length > 0);
	assert(x >= 0);
	assert(x < (int) this->map.size());
	assert(y >= 0);
	assert(y < (int) this->map[x].size());
	int realLength = drawLine(x, y, direction, length, OCCUPIED);
	if(realLength == 0) return;
	shared_ptr<Wall> wall(new Wall(x, y, direction, realLength));
	this->walls.push_back(wall);
}

/**
 * Generate a Steam which includes a Unicode representation of the map and provides Data about the map.
 */
ostream& theseus::map::operator<<(ostream& os, const Map& map) {
	int i = 0, j = 0;

	for(i = 0; i < (int) map.map[0].size(); i++) {
		for(j = 0; j < (int) map.map.size(); j++) {
			switch(map.map[j][i]) {
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

	os << "Details:" << endl;
	os << "\tCounted " << map.walls.size() << " walls." << endl;
	os << "\tCounted " << map.rooms.size() << " rooms." << endl;

	return os;
}
