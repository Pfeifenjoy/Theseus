#ifndef THESEUS_MAP_WALL
#define THESEUS_MAP_WALL
#include "Room.hpp"
#include "Map.hpp"
#include <SFML/System.hpp>
namespace theseus {
namespace map {
	/**
	 * A Wall is seperates corridores and rooms.
	 */
	class Wall {
		private:
			/**
			 * This vector specifies where to put the wall.
			 */
			sf::Vector2<int> position;
		  	/**
			 * This vector represents the wall.
			 */
			sf::Vector2<int> wall;

			/**
			 * The amount of pixel which will be increased by an increment.
			 */
			const int increment = 80;

			/**
			 * Defines the size of a door.
			 */
			const int doorSize = 80;
		public:
			/**
			 * This constructor will create an empty wall which just
			 * specifies the location of the wall and in which location
			 * it will grow.
			 * @param direction The direction in which the wall can grow.
			 */
			Wall(sf::Vector2<int> direction);

			/**
			 * Increases the length of the wall by 1.
			 * Can only be done when a map is specified.
			 */
			Wall& operator++() throw (Collision, NoMap);

			void setMap(Map&);
	};
}
}
#endif
