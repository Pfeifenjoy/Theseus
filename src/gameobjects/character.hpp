#ifndef _THESEUS_GAME_OBJECTS_CHARACTER_H
#define _THESEUS_GAME_OBJECTS_CHARACTER_H

#include "../engine/gameobject.hpp"
#include "../engine/components/update.hpp"
#include "../engine/components/animation.hpp"
#include "../engine/components/speed.hpp"
#include "../engine/components/collisionresolver.hpp"
#include <SFML/System.hpp>

namespace theseus
{
namespace gameobjects
{
	class Character
		: public engine::GameObject
		, public virtual engine::components::Animation
		, public virtual engine::components::Speed
		, public virtual engine::components::CollisionResolver
	{
	private:
		// state changes
		sf::Vector2i direction;

	public:
		void setDirection(sf::Vector2i direction, bool force_update = false);
		//---- Constructor --------------------------------------------------------------------------------------

		Character();

		//---- Destructor ---------------------------------------------------------------------------------------

		~Character();
	};
}
}

#endif
