/**
 * @author Arwed Mett
 */
#ifndef THESEUS_LEVEL_DESCRIPTION
#define THESEUS_LEVEL_DESCRIPTION
#include <memory>
#include <vector>
#include "positionable.hpp"
#include "room-description.hpp"
#include "../gameobjects/player.hpp"

namespace theseus {
	namespace map {
		class LevelDescription {
		private:
			std::vector<std::unique_ptr<Positionable> > freeObjects;
			std::vector<std::unique_ptr<RoomDescription> > rooms;
			std::unique_ptr<theseus::gameobjects::Player> player;
			sf::Vector2f dimensions;
		public:
			LevelDescription(sf::Vector2f dimensions) : dimensions(dimensions) {}
			sf::Vector2f getDimensions();
			std::vector<std::unique_ptr<Positionable> > getFreeObjects();
			std::vector<std::unique_ptr<RoomDescription> > getRooms();
			std::unique_ptr<theseus::gameobjects::Player> getPlayer();
			void addFreeGameObject(std::unique_ptr<Positionable>);
			void addFreeGameObjects(std::vector<std::unique_ptr<Positionable> >);
			void addRoom(std::unique_ptr<RoomDescription>);
			void addRooms(std::vector<std::unique_ptr<RoomDescription> >);
		};
	}
}
#endif
