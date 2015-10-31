/**
 * author Arwed Mett
 */

#ifndef THESEUS_MAP_WALL
#define THESEUS_MAP_WALL
#include <SFML/Graphics.hpp>
#include <memory>

namespace theseus {
namespace map {
	enum Direction {
		NORTH = 0,
		EAST = 1,
		SOUTH = 2,
		WEST = 3
	};
	class Wall {
		private:
			int x;
			int y;
			int blockLength;
			Direction direction;
			int blockSize;
		public:
			Wall(int x, int y, Direction direction, int maxBlockLength) : x(x), y(y), blockLength(maxBlockLength), direction(direction) {}
			int getBlockLength();
			int getBlockSize();
	};
}
}
#endif
