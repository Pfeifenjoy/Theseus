/**
*  @Author: Leon Mutschke
*/


#ifndef _THESEUS_GAME_OBJECTS_HOFMANN_H
#define _THESEUS_GAME_OBJECTS_HOFMANN_H

#include "professor.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Hofmann
			: public Professor 
		{
		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Hofmann();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Hofmann();
		};
	}
}

#endif
