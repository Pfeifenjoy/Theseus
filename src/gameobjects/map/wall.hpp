/**
 * author Arwed Mett
 */

#ifndef THESEUS_MAP_WALL
#define THESEUS_MAP_WALL
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "brick.hpp"
#include "../../engine/gameobject.hpp"

namespace theseus {
namespace gameobjects {
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
			std::vector<std::unique_ptr<Brick> > bricks;

		public:
			Wall(int x, int y, Direction direction, int maxBlockLength);
			void setSpecialBrick(int, int, BrickType);
			std::vector<std::unique_ptr<theseus::engine::GameObject> > getGameObjects();
			int getBlockLength();
			int getBlockSize();
	};
}
}
}
#endif
