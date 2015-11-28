/**
 * Autor: Tobias Dorra
 */
#ifndef _THESEUS_ENGINE_COMPONENTS_COLLISION_DETECTOR_H
#define _THESEUS_ENGINE_COMPONENTS_COLLISION_DETECTOR_H 

#include "solide.hpp"
#include "base.hpp"
#include "../publisher.hpp"
#include <SFML/System.hpp>

namespace theseus
{
namespace engine
{
class Scene;
namespace components
{

/**
 * This component provides an event that is triggered, when thhe game object overlaps with an other solide game object.
 */
class CollisionDetector : public virtual Base
			, public virtual Solide
{
	private:
		void onUpdateRegistration(Scene& scene);
		void onPositionChanged(sf::Vector2f oldPosition, sf::Vector2f newPosition);

		bool reCheckCollision;

	protected:
		/**
		 * The event that will be triggered, when a collision was detected.
		 */
		Publisher<const Solide&> evCollisionDetected;

	public:
		/**
		 * Constructor
		 */
		CollisionDetector();

		/**
		 * Destructor
		 */
		virtual ~CollisionDetector(); 

		/**
		 * Gets called by the scene, when it detected a collision!
		 */
		void handleCollision(const Solide& other);
};

}
}
}

#endif
