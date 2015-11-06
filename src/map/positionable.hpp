#ifndef THESEUS_MAP_POSITIONABLE
#define THESEUS_MAP_POSITIONABLE
#include "../engine/gameobject.hpp"
#include "../engine/components/collisionresolver.hpp"

namespace theseus {
namespace map {
	class Positionable
		: public theseus::engine::GameObject
		, public virtual theseus::engine::components::CollisionResolver
	{

	};
}
}
#endif
