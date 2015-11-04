/**
 * @author Arwed Mett
 */
#ifndef THESEUS_LEVEL_DESCRIPTION
#define THESEUS_LEVEL_DESCRIPTION
#include <memory>
#include <vector>
#include "../engine/gameobject.hpp"
#include "room-description.hpp"
#include "../gameobjects/player.hpp"

namespace theseus {
	namespace map {
		class LevelDescription {
		private:
			std::vector<std::unique_ptr<theseus::engine::GameObject> > freeObjects;
			std::vector<std::unique_ptr<RoomDescription> > rooms;
			std::unique_ptr<theseus::gameobjects::Player> player;
		public:
			std::vector<std::unique_ptr<theseus::engine::GameObject> > getFreeObjects();
			std::vector<std::unique_ptr<RoomDescription> > getRooms();
			std::unique_ptr<theseus::gameobjects::Player> getPlayer();
			void addGameFreeObject(std::unique_ptr<theseus::engine::GameObject>);
			void addGameFreeObjects(std::vector<std::unique_ptr<theseus::engine::GameObject> >);
			void addRoom(std::unique_ptr<RoomDescription>);
			void addRooms(std::vector<std::unique_ptr<RoomDescription> >);
		};
	}
}
#endif
