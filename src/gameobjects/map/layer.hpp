/**
 * @author Arwed Mett
 */

#ifndef THESEUS_MAP_LAYER
#define THESEUS_MAP_LAYER
#include "wall.hpp"
#include "room.hpp"
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
			std::vector<std::unique_ptr<Wall> > walls;
			std::vector<std::vector<FieldStatus> > layer;
			std::vector<std::unique_ptr<Room> > rooms;
			int drawLine(int x, int y, Direction direction, int length, FieldStatus status);
			void setSpecialBricks();
			std::vector<std::unique_ptr<Brick> > bricks;
			void generateGameObjectField();
		public:
			/**
			 * Initialize a squared layer.
			 * @param width {int}
			 * @param height {int}
			 */
			Layer(int width, int height);
			void printSquare(int x, int y, int width, int height);
			void fillWithRooms(int minSize, int maxSize, int numWalls);
			void addRoom(int x, int y, int width, int height);
			bool checkField(int x, int y, int width = 1, int height = 1);
			/**
			 * Fill the layer with random walls.
			 * This generates a labyrinth.
			 * @param minLength {int} Minimum length of a wall. This might not always happen.
			 * @param maxLength {int} Maximum length of a wall.
			 * @param granularity {int} Sets the space between the walls.
			 * @param numWalls {int} Maximum amount of walls which will be generated.
			 */
			void fillWithWalls(int minLength, int maxLength, int granularity, int numWalls);
			/**
			 * This will try to add a Wall to the layer, by a given length and position.
			 * @param x {int} x Coordinate
			 * @param y {int} y Coordinate
			 * @param direction {theseus::map::Direction}
			 * @param length {int} maximal Length of the wall.
			 */
			void addWall(int x, int y, Direction direction, int length);
			std::vector<std::unique_ptr<theseus::engine::GameObject> > getGameObjects();
			/**
			 * Generate a Steam which includes a Unicode representation of the layer and provides Data about the layer.
			 */
			friend std::ostream& operator<<(std::ostream&, const Layer&);
	};
}
}
}
#endif
