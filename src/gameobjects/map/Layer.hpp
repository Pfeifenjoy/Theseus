/**
 * author Arwed Mett
 */

#ifndef THESEUS_MAP_LAYER
#define THESEUS_MAP_LAYER
#include "Wall.hpp"
#include "Room.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

namespace theseus {
namespace gameobjects {
namespace map {
	enum FieldStatus {
		FREE,
		OCCUPIED,
		VERTICAL_RESTRICTED,
		HORIZONTAL_RESTRICTED,
		RESTRICTED
	};
	class Layer;
	std::ostream& operator<<(std::ostream&, const Layer&);
	class Layer {
		private:
			std::vector<std::shared_ptr<Wall> > walls;
			std::vector<std::vector<FieldStatus> > layer;
			std::vector<std::shared_ptr<Room> > rooms;
			int drawLine(int x, int y, Direction direction, int length, FieldStatus status);
		public:
			Layer(int width, int height);
			void printSquare(int x, int y, int width, int height);
			void fillWithRooms(int minSize, int maxSize, int numWalls);
			void addRoom(int x, int y, int width, int height);
			bool checkField(int x, int y, int width = 1, int height = 1);
			void fillWithWalls(int minLength, int maxLength, int granularity, int numWalls);
			void addWall(int x, int y, Direction direction, int length);
			friend std::ostream& operator<<(std::ostream&, const Layer&);
	};
}
}
}
#endif
