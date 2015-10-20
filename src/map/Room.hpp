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
			/**
			 * The room will randomly generate a position within an area
			 * of 10000*10000
			 */
			Room();
			/**
			 * The room will randomly generate a position by a given size.
			 * @param mapWidth The width of the map where the Room is placed.
			 * @param mapHeight The height of the map where the Room is placed.
			 */
			Room(int mapWidth, int mapHeight);

			void setMap(Map&);

	};
}
}
#endif
