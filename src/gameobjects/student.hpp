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
			void onUpdate(float timePassed);
			
			// Amough of time (in secs) the exmatriculation message have to be received
			float exmatriculationProcessActive;

			// Amough of points wich will be reduced if the exmatriculation process is active(reduced by small floats)
			float exmatriculationProgress;

			bool exmatriculationable;
			bool progressbarActive;
			
		protected:
			bool professorSendedExmatriculationMessage = false;

			void exmatriculation(const theseus::messages::Exmatriculation& message);

			// Method will be called if student gets exmatriculated
			virtual bool exmatriculationTick(const theseus::messages::Exmatriculation& message);
			virtual void exmatriculationDone();
			
		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Student();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Student();

			// Sets if the student is exmatriculateable (default: true)
			void setExmatriculationable(bool value);

		};
	}
}

#endif
