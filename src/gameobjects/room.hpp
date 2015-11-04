/**
 * @author Arwed Mett
 */
#ifndef THESEUS_GAMEOBJECTS_ROOM
#define THESEUS_GAMEOBJECTS_ROOM
#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/Graphics.hpp>
namespace theseus {
namespace gameobjects {
	class Room : public engine::GameObject
			   //, public virtual engine::components::Sprite
   	{
		public:
			Room(sf::Vector2f position, sf::Vector2f size);
			virtual ~Room();
	};
}
}
#endif
