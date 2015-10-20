#ifndef THESEUS_MAP_MAP
#define THESEUS_MAP_MAP
#include "Room.hpp"
#include "Wall.hpp"
#include <vector>
#include <iostream>
namespace theseus {
namespace map {
	class Map;
	std::ostream& operator<<(std::ostream& os, Room& room);
	std::ostream& operator<<(std::ostream& os, Wall& room);
	class Map {
		private:
			int width;
			int heigth;
			std::vector<Room> rooms;
			std::vector<Wall> walls;

		public:
			Map();
			int getWidth();
			int getHeight();
			friend std::ostream& operator<<(std::ostream&, Room&);
			friend std::ostream& operator<<(std::ostream&, Wall&);

	};
}
}
#endif
