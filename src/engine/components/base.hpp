#ifndef _THESEUS_ENGINE_COMPONENTS_BASE_H
#define _THESEUS_ENGINE_COMPONENTS_BASE_H

#include "../publisher.hpp"

namespace theseus
{
namespace engine
{
class Scene;
namespace components
{
	class Base
	{
	protected:

		Publisher<Scene&> evRegisterComponents;
		Publisher<Scene&> evUnregisterComponents;
		Publisher<Scene&> evUpdateComponentRegistrations;
	public:
		virtual ~Base();

		void registerComponents(Scene& scene);
		void refreshComponentRegistrations(Scene& scene);
		void unregisterComponents(Scene& scene);

	};
}
}
}

#include "../scene.hpp"

#endif
