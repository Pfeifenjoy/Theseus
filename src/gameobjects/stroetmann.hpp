/**
*  @Author: Leon Mutschke
*/


#ifndef _THESEUS_GAME_OBJECTS_STROETMANN_H
#define _THESEUS_GAME_OBJECTS_STROETMANN_H

#include "professor.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Stroetmann
			: public Professor 
		{
		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Stroetmann();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Stroetmann();
		};
	}
}

#endif
