/**
*  @Author: Leon Mutschke
*/


#ifndef _THESEUS_GAME_OBJECTS_GLASER_H
#define _THESEUS_GAME_OBJECTS_GLASER_H

#include "professor.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Glaser
			: public Professor
		{
		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Glaser();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Glaser();
		};
	}
}

#endif
