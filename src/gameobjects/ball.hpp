#ifndef _THESEUS_GAME_OBJECTS_BALL_H
#define _THESEUS_GAME_OBJECTS_BALL_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include "../engine/components/speed.hpp"

namespace theseus
{
namespace engine
{
	class Scene;
}
namespace gameobjects
{
	class Ball 
		: public engine::GameObject
		, public virtual engine::components::Sprite
		, public virtual engine::components::Speed
	{
	public:
		//---- Constructor --------------------------------------------------------------------------------------
		
		Ball(engine::Scene& scene);

		//---- Destructor ---------------------------------------------------------------------------------------
		
		~Ball();
	};
}
}

#endif
