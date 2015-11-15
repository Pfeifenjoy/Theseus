/**
*  @Author: Leon Mutschke
*/


#ifndef _THESEUS_GAME_OBJECTS_KRUSE_H
#define _THESEUS_GAME_OBJECTS_KRUSE_H

#include "professor.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Kruse
			: public Professor
		{
		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Kruse();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Kruse();
		};
	}
}

#endif
