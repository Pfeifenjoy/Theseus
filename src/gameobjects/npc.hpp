/**
*  @Author: Tobias Dorra, Leon Mutschke, Dominic Steinhauser
*/

#ifndef _THESEUS_GAME_OBJECTS_NPC_H
#define _THESEUS_GAME_OBJECTS_NPC_H

#include "../engine/components/messagesender.hpp"
#include "../gameobjects/student.hpp"
#include <SFML/System.hpp>
#include "character.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class NPC
			: public Student
			, public virtual engine::components::Update
			, public virtual engine::components::Animation
			, public virtual engine::components::Speed
			, public virtual engine::components::MessageSender<theseus::messages::Exmatriculation>
		{
		private:
			// events
			void onUpdate(float passedTime);
			float time_passed = 0;
			void onCollision(const theseus::engine::components::Solide&);
			void changeDirection();

			// exmatriculation		
			float exmatriculation_radius = 80; 	// where the exmatriculation message is sent to
			float exmatriculation_speed = 1; 	// how fast the npc exmatriculates other poor students

			// npx behaivour values
			bool exmatriculatedBool;
			bool exmatriculate;

			// Method will be called if the npc is exmatriculated
			void exmatriculationDone();

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			NPC();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~NPC();

			// Sets if the npc can exmatriculate other npc/players
			void setExmatriculate();
		};
	}
}

#endif
