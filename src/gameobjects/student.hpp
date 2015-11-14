/**
*  @Author: Philipp Pütz
*/


#ifndef _THESEUS_GAME_OBJECTS_STUDENT_H
#define _THESEUS_GAME_OBJECTS_STUDENT_H

#include "../engine/gameobject.hpp"
#include "../engine/components/update.hpp"
#include "../engine/components/animation.hpp"
#include "../engine/components/speed.hpp"
#include "../engine/components/messagereceiver.hpp"
#include "../messages/exmatriculation.hpp"
#include <SFML/System.hpp>
#include "character.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Student
			: public Character
			, public virtual engine::components::Update
			, public virtual engine::components::Animation
			, public virtual engine::components::Speed
			, public virtual engine::components::MessageReceiver<theseus::messages::Exmatriculation>

		{
		private:
			float exmatriculationProcess;
			float exmatricualtionProcessActive;			

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Student();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Student();

			void exmatriculation(const theseus::messages::Exmatriculation& message);

			virtual void exmatriculationDone();

		};
	}
}

#endif
