#ifndef _THESEUS_ENGINE_COMPONENTS_BASE_H
#define _THESEUS_ENGINE_COMPONENTS_BASE_H

#include "../publisher.hpp"

namespace theseus
{
namespace engine
{
class Scene;
class GameObject;
namespace components
{
	class Base
	{
	private:
		bool theEndIsNear = false;

	protected:

		/**
		 * Lifetime events.
		 *
		 * evRegisterComponents:
		 * 	is invoked after the game object was added to a scene.
		 * 	components are supposed to do registration stuff with the scene here.
		 *
		 * evUnregisterComponents:
		 * 	gets invoked after the game object was removed from the scene.
		 * 	When this event occurs, components are 
		 * 	supposed to unregister themselves at the scene.
		 *
		 * evUpdateComponentRegistrations:
		 * 	this event is invoked on a regular basis, whenever the game object
		 * 	might has changed.
		 * 	Components are supposed to inform the scene of their 
		 * 	current state (if it has changed) in this event.
		 */
		Publisher<Scene&> evRegisterComponents;
		Publisher<Scene&> evUnregisterComponents;
		Publisher<Scene&> evUpdateComponentRegistrations;

		/**
		 * As it is technical impossible for a GO to
		 * destruct itself, this method informs the scene
		 * to do this job instead.
		 */
		void selfDestruct();
	public:
		virtual ~Base();

		void registerComponents(Scene& scene);
		void refreshComponentRegistrations(Scene& scene);
		void unregisterComponents(Scene& scene);

		bool needsDestruction() const;
	};
}
}
}

#include "../scene.hpp"

#endif
