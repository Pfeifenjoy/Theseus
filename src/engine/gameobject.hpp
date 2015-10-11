#ifndef _THESEUS_ENGINE_GAME_OBJECT_H
#define _THESEUS_ENGINE_GAME_OBJECT_H

#include "components/base.hpp"

namespace theseus
{
namespace engine
{
	class GameObject : public virtual components::Base
	{
	public:
		//---- Constructors ---------------------------------------------------------------------------------------
		
		GameObject(Scene& scene);
	
		//---- Destructor -----------------------------------------------------------------------------------------
		
		virtual ~GameObject();

	};
}
}
#endif
