#ifndef THESEUS_MAP_POSITIONABLE
#define THESEUS_MAP_POSITIONABLE
#include "../engine/gameobject.hpp"
#include "../engine/components/solide.hpp"

namespace theseus {
namespace map {
	class Positionable
		: public virtual theseus::engine::GameObject
		, public virtual theseus::engine::components::Solide
	{

	};
}
}
#endif
