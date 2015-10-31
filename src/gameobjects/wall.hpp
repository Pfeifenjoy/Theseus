#ifndef _THESEUS_GAME_OBJECTS_WALL_H
#define _THESEUS_GAME_OBJECTS_WALL_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"

namespace theseus
{
	namespace engine
	{
		class Scene;
	}
	namespace gameobjects
	{
		class Wall
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:
			int wallType;
			sf::Vector2f size;
			sf::Vector2f position;

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Wall(int wallType, sf::Vector2f position, sf::Vector2f size);

			//---- Destructor ---------------------------------------------------------------------------------------

			~Wall();

		};
	}
}

#endif

