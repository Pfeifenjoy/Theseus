#ifndef _THESEUS_ENGINE_GAME_OBJECT_H
#define _THESEUS_ENGINE_GAME_OBJECT_H

#include "components/base.hpp"

namespace theseus
{
namespace engine
{
	class Scene;

	class GameObject : public virtual components::Base
	{
	public:
	
		//---- Constructors / Destructor --------------------------------------------------------------------------
		
		virtual ~GameObject();

		//---- Methods --------------------------------------------------------------------------------------------
		
		void registerComponents(Scene& scene);
		void unregisterComponents(Scene& scene);

	};
}
}

#endif
