/**
 * @autor Arwed Mett
 */
#ifndef THESEUS_MAP_ROOMDESCRIPTION
#define THESEUS_MAP_ROOMDESCRIPTION
#include <vector>
#include <memory>
#include "../engine/gameobject.hpp"
#include <SFML/Graphics.hpp>

namespace theseus {
namespace map {
	class RoomDescription {
		private:
			sf::Vector2f position;
			float width;
			float height;
			std::vector<std::unique_ptr<theseus::engine::GameObject> > gameobjects;
		public:
			RoomDescription(float width, float height);
			void setPosition(sf::Vector2f);
			void addGameObject(std::unique_ptr<engine::GameObject>);
			float getWidth();
			float getHeight();
			std::vector<std::unique_ptr<theseus::engine::GameObject> > getGameObjects();

	};
}
}
#endif
