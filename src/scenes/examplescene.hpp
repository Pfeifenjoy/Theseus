#ifndef _THESEUS_SCENES_EXAMPLE_SCENE_H
#define _THESEUS_SCENES_EXAMPLE_SCENE_H

#include "../engine/scene.hpp"
#include <memory>

namespace theseus
{
namespace engine
{
	class Game;
}
namespace gameobjects
{
	class Ball;
}
namespace scenes
{
	class ExampleScene : public engine::Scene
	{
	private:
		std::unique_ptr<gameobjects::Ball> ball;

	public:
		
		//---- Constructors ------------------------------------------------------------------------------
		
		ExampleScene(engine::Game&);

		//---- Destructor --------------------------------------------------------------------------------
		
		~ExampleScene();
	};
}
}
#endif
