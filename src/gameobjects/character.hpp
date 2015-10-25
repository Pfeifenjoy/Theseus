#ifndef _THESEUS_GAME_OBJECTS_CHARACTER_H
#define _THESEUS_GAME_OBJECTS_CHARACTER_H

#include "../engine/gameobject.hpp"
#include "../engine/components/animation.hpp"

namespace theseus
{
namespace gameobjects
{
	class Character 
		: public engine::GameObject
		, public virtual engine::components::Animation
	{
	private:
		void onUpdate(float passedTime);

	public:
		//---- Constructor --------------------------------------------------------------------------------------
		
		Character();

		//---- Destructor ---------------------------------------------------------------------------------------
		
		~Character();
	};
}
}

#endif
