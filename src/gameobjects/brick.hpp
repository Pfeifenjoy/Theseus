/**
 * @author Philipp Pütz, Arwed Mett
 */
#ifndef _THESEUS_GAME_OBJECTS_BRICK_H
#define _THESEUS_GAME_OBJECTS_BRICK_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include "../engine/components/solide.hpp"

namespace theseus
{
namespace engine
{
	class Scene;
}
namespace gameobjects
{
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
		, public virtual theseus::engine::components::Solide
	{
	private:
		int brickType;

	public:
		//---- Constructor --------------------------------------------------------------------------------------

		Brick(BrickType, int x, int y);

		//---- Destructor ---------------------------------------------------------------------------------------

		~Brick();

		void setType(BrickType);

		enum { WIDTH = 32, HEIGHT = 64, OFFSET=6, LAYER=2 };
	};
}
}

#endif

