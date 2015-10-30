#include "Map.hpp"
#include <cassert>
#include <time.h>

using namespace theseus::map;
using namespace std;

Map::Map(int width, int height) {
	srand(time(NULL));
	this->map = vector<vector<FieldStatus> > (width, vector<FieldStatus> (height, FREE));
	fillWithWalls(3, 20, 2, 100);
}

void Map::fillWithWalls(int minLength, int maxLength, int granularity, int numWalls) {
	assert(numWalls >= 0);
	assert(granularity % 2 == 0);
	assert(minLength > 0);
	assert(maxLength > 0 && maxLength > minLength);
    while(numWalls--) {
        int x = granularity * (rand() % ((this->map.size()) / granularity));
        int y = granularity * (rand() % ((this->map[x].size()) / granularity));
        Direction dir = Direction(rand() % 4);
        int length = granularity * ((rand() % (maxLength -minLength)) + minLength) ;
        this->addWall(x, y, dir, length);
    }
}

void Map::addWall(int x, int y, Direction direction, int length) {
	assert(length > 0);
	assert(x >= 0);
	assert(x < (int) this->map.size());
	assert(y >= 0);
	assert(y < (int) this->map[x].size());
	int realLength = 0;
	if(this->map[x][y]) return;
	while(length--) {
		if(x < 0 || y < 0 || x >= (int) map.size() || y >= (int) map[x].size() || this->map[x][y]) break;
		map[x][y] = OCCUPIED;
		realLength++;
		switch(direction) {
			case NORTH: y++; break;
			case WEST: x++; break;
			case SOUTH: y--; break;
			case EAST: x--; break;
		}
	}
	assert(realLength > 0);
	unique_ptr<Wall> wall(new Wall(x, y, direction, realLength));
	this->walls.push_back(move(wall));
}

ostream& theseus::map::operator<<(ostream& os, const Map& map) {
	int i = 0, j = 0;

	for(i = 0; i < (int) map.map.size(); i++) {
		for(j = 0; j < (int) map.map[i].size(); j++) {
			os << (map.map[i][j] ? "\x1B[33m\u2588" : "\x1B[34m\u2588");
		}
		os << endl;
	}
	os << "\x1B[0m";
	os << "Counted " << map.walls.size() << " walls." << endl;
	return os;
}
