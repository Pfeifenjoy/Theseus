#ifndef _THESEUS_ENGINE_COMPONENTS_COLLISION_RESOLVER_H
#define _THESEUS_ENGINE_COMPONENTS_COLLISION_RESOLVER_H value

#include "collisiondetector.hpp"

namespace theseus
{
namespace engine
{
namespace components
{

class CollisionResolver : public virtual CollisionDetector
{
	private:
		void onCollisionDetected(const components::Solide&);
	protected:
	public:
		CollisionResolver();
		virtual ~CollisionResolver();
};

}
}
}

#endif
