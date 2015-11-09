/**
 * @author Arwed Mett
 */
#ifndef THESEUS_LEVEL_DESCRIPTION
#define THESEUS_LEVEL_DESCRIPTION
#include <memory>
#include <vector>
#include "../engine/components/positionable.hpp"
#include "room-description.hpp"
#include "../gameobjects/player.hpp"
#include "../gameobjects/brick.hpp"

namespace theseus {
	namespace map {
		class LevelDescription {
		private:
			std::vector<std::unique_ptr<theseus::engine::components::Positionable> > freeObjects;
			std::vector<std::unique_ptr<RoomDescription> > rooms;
			std::unique_ptr<theseus::gameobjects::Player> player;
			sf::Vector2f dimensions;
			sf::Vector2f minRoomSize = sf::Vector2f(theseus::gameobjects::Brick::WIDTH * 7, theseus::gameobjects::Brick::HEIGHT * 7);
			sf::Vector2f maxRoomSize = sf::Vector2f(theseus::gameobjects::Brick::WIDTH * 15, theseus::gameobjects::Brick::HEIGHT * 15);
			int maxAmountOfStandardRooms = 5;
		public:
			LevelDescription(sf::Vector2f dimensions) : dimensions(dimensions) {}
			sf::Vector2f getDimensions();
			std::vector<std::unique_ptr<theseus::engine::components::Positionable> > getFreeObjects();
			std::vector<std::unique_ptr<RoomDescription> > getRooms();
			std::unique_ptr<theseus::gameobjects::Player> getPlayer();
			sf::Vector2f getMinRoomSize();
			sf::Vector2f getMaxRoomSize();
			int getMaxAmountOfStandardRooms();
			void addFreeGameObject(std::unique_ptr<theseus::engine::components::Positionable>);
			void addFreeGameObjects(std::vector<std::unique_ptr<theseus::engine::components::Positionable> >);
			void addRoom(std::unique_ptr<RoomDescription>);
			void addRooms(std::vector<std::unique_ptr<RoomDescription> >);
			void setMinRoomSize(sf::Vector2f);
			void setMaxRoomSize(sf::Vector2f);
			void setMaxAmountOfStandardRooms(int);
		};
	}
}
#endif
