#ifndef _THESEUS_SCENES_EXAMPLE_SCENE_H
#define _THESEUS_SCENES_EXAMPLE_SCENE_H

#include "../engine/scene.hpp"
#include "../gameobjects/ball.hpp"

namespace theseus
{
namespace engine
{
	class Game;
}
namespace scenes
{
	class ExampleScene : public engine::Scene
	{
	private:
		gameobjects::Ball ball;

	public:
		
		//---- Constructors ------------------------------------------------------------------------------
		
		ExampleScene(engine::Game&);
	};
}
}
#endif
