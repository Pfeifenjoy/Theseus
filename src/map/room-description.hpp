/**
 * @autor Arwed Mett
 */
#ifndef THESEUS_MAP_ROOMDESCRIPTION
#define THESEUS_MAP_ROOMDESCRIPTION
#include <vector>
#include <memory>
#include "../engine/gameobject.hpp"
#include <SFML/Graphics.hpp>
#include "../engine/components/positionable.hpp"

namespace theseus {
namespace map {

	/**
	 * Describes special rooms.
	 * Will be called by the Layer / Generator.
	 */
	class RoomDescription {
		private:
			sf::Vector2f position;
			float width;
			float height;
			std::vector<std::unique_ptr<theseus::engine::components::Positionable> > gameobjects;
		public:
			RoomDescription(float width, float height);
			//Don't call it manually. It will not work.
			void setPosition(sf::Vector2f);
			void addGameObject(std::unique_ptr<theseus::engine::components::Positionable>);
			float getWidth();
			float getHeight();
			std::vector<std::unique_ptr<theseus::engine::components::Positionable> > getGameObjects();

	};
}
}
#endif
