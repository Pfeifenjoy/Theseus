/**
 * @autor Arwed Mett
 */
#ifndef THESEUS_MAP_ROOM
#define THESEUS_MAP_ROOM
#include <vector>
#include <memory>
#include "../engine/gameobject.hpp"

namespace theseus {
namespace map {
	class Room {
		private:
			sf::Vector2f position;
			float width;
			float height;
			std::vector<std::unique_ptr<theseus::engine::GameObject> > gameobjects;
		public:
			Room(float width, float height) :width(width), height(height) {}
			void setPosition(sf::Vector2f);
			void addGameObject(std::shared_ptr<engine::GameObject>);
			std::vector<std::unique_ptr<theseus::engine::GameObject> > getGameObjects();

	};
}
}
#endif
