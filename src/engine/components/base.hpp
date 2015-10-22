#ifndef _THESEUS_ENGINE_COMPONENTS_BASE_H
#define _THESEUS_ENGINE_COMPONENTS_BASE_H

#include "../publisher.hpp"
#include "../scene.hpp"

namespace theseus
{
namespace engine
{

namespace components
{
	class Base
	{
	protected:

		Publisher<Scene&> evRegisterComponents;

	};
}
}
}

#endif
