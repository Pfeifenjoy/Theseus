#ifndef THESEUS_MAP_ROOM
#define THESEUS_MAP_ROOM
#include "Wall.hpp"
#include "Map.hpp"
#include <SFML/System.hpp>
namespace theseus {
namespace map {
	/**
	 * A room will be set randomly at the beginning on the map.
	 * Rooms represent large places which do not contain walls.
	 */
	class Room {
		private:
			/**
			 * Specifies where to place the Room.
			 * The x coordinate ranges from the top of the screen
			 * to the bottum.
			 * The y coordinate ranges from the left of the screen
			 * to the right.
			 */
			sf::Vector2<int> position;
			/**
			 * This vector specifies the diagonal of the room.
			 */
			sf::Vector2<int> span;
			/**
			 * Every room consists has walls which can have an entrance.
			 */
			std::vector<Wall> walls;
		public:
			Room(Map);
	};
}
}
#endif
