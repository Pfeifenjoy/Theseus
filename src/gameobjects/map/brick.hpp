#ifndef _THESEUS_GAME_OBJECTS_BRICK_H
#define _THESEUS_GAME_OBJECTS_BRICK_H

#include "../../engine/gameobject.hpp"
#include "../../engine/components/sprite.hpp"

namespace theseus
{
namespace engine
{
	class Scene;
}
namespace gameobjects
{
namespace map {
	enum BrickType {
		HORIZONAL,
		VERTICAL,
		EDGE_LEFT_BOTTOM,
		EDGE_LEFT_TOP,
		EDGE_RIGHT_BOTTOM,
		EDGE_RIGHT_TOP,
		LEFT_MIDDLE,
		LEFT_END,
		RIGHT_MIDDLE,
		RIGHT_END,
		BOTTOM_END,
		TOP_END,
		CROSS,
		T_CROSS,
		T_UPSIDEDOWN_CROSS
	};
	class Brick
		: public theseus::engine::GameObject
		, public virtual theseus::engine::components::Sprite
	{
	private:
		int brickType;
		sf::Vector2f size;
		sf::Vector2f position;

	public:
		//---- Constructor --------------------------------------------------------------------------------------

		Brick(BrickType brickType, sf::Vector2f position, sf::Vector2f size);

		//---- Destructor ---------------------------------------------------------------------------------------

		~Brick();

	};
}
}
}

#endif

