#ifndef _THESEUS_GAME_OBJECTS_BALL_H
#define _THESEUS_GAME_OBJECTS_BALL_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"

namespace theseus
{
namespace gameobjects
{
	class Ball : public engine::GameObject, public virtual engine::components::Sprite
	{
	public:
		//---- Constructor -------------------------------------------------------------------------------------------
		
		Ball();
	};
}
}

#endif
