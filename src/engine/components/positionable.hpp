/**
 * @autor Arwed Mett
 */
#ifndef THESEUS_MAP_POSITIONABLE
#define THESEUS_MAP_POSITIONABLE
#include "../gameobject.hpp"
#include "position.hpp"
#include <SFML/Graphics.hpp>

namespace theseus {
namespace engine {
namespace components {
	class Positionable
		: public theseus::engine::GameObject
		, public virtual Position
	{
		private:
			sf::Vector2f size;
		public:
			void setSize(sf::Vector2f);
			sf::Vector2f getSize();
	};
}
}
}
#endif
