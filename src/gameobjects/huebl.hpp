/**
*  @Author: Leon Mutschke
*/


#ifndef _THESEUS_GAME_OBJECTS_HUEBL_H
#define _THESEUS_GAME_OBJECTS_HUEBL_H

#include "professor.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Huebl
			: public Professor 
		{
		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Huebl();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Huebl();
		};
	}
}

#endif
