/**
*  @Author: Leon Mutschke
*/
#ifndef _THESEUS_GAME_OBJECTS_RUNGE_H
#define _THESEUS_GAME_OBJECTS_RUNGE_H

#include "professor.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Runge
			: public Professor 
		{
		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Runge();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Runge();
		};
	}
}

#endif
