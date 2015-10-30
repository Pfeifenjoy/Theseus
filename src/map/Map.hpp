/**
 * author Arwed Mett
 */

#ifndef THESEUS_MAP_MAP
#define THESEUS_MAP_MAP
#include "Wall.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

namespace theseus {
namespace map {
	enum FieldStatus {
		FREE,
		OCCUPIED,
		VERTICAL_RESTRICTED,
		HORIZONTAL_RESTRICTED,
		RESTRICTED
	};
	class Map;
	std::ostream& operator<<(std::ostream&, const Map&);
	class Map {
		private:
			std::vector<std::unique_ptr<Wall> > walls;
			std::vector<std::vector<FieldStatus> > map;
		public:
			Map(int width, int height);
			void fillWithWalls(int minLength, int maxLength, int granularity, int numWalls);
			void addWall(int x, int y, Direction direction, int length);
			friend std::ostream& operator<<(std::ostream&, const Map&);
	};
}
}
#endif
