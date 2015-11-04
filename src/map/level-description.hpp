/**
 * @author Arwed Mett
 */
#ifndef THESEUS_LEVEL_DESCRIPTION
#define THESEUS_LEVEL_DESCRIPTION
#include <memory>
#include <vector>
#include "../engine/gameobject.hpp"
#include "room.hpp"
#include "../gameobjects/player.hpp"

namespace theseus {
namespace map {
	class LayerDescription {
		private:
			std::vector<std::unique_ptr<theseus::engine::GameObject> > freeObjects;
			std::vector<std::unique_ptr<Room> > rooms;
			std::unique_ptr<theseus::gameobjects::Player> player;
		public:
			std::vector<std::unique_ptr<theseus::engine::GameObject> > getFreeObjects();
			std::vector<std::unique_ptr<Room> > getRooms();
			std::unique_ptr<theseus::gameobjects::Player> getPlayer();
	};
}
}
#endif
