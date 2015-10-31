/**
 * author Arwed Mett
 */

#ifndef THESEUS_MAP_MAP
#define THESEUS_MAP_MAP
#include "Wall.hpp"
#include "Room.hpp"
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
			std::vector<std::shared_ptr<Wall> > walls;
			std::vector<std::vector<FieldStatus> > map;
			std::vector<std::shared_ptr<Room> > rooms;
			int drawLine(int x, int y, Direction direction, int length, FieldStatus status);
		public:
			Map(int width, int height);
			void printSquare(int x, int y, int width, int height);
			void fillWithRooms(int minSize, int maxSize, int numWalls);
			void addRoom(int x, int y, int width, int height);
			bool checkField(int x, int y, int width = 1, int height = 1);
			void fillWithWalls(int minLength, int maxLength, int granularity, int numWalls);
			void addWall(int x, int y, Direction direction, int length);
			friend std::ostream& operator<<(std::ostream&, const Map&);
	};
}
}
#endif
