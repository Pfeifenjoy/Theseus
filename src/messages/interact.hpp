/**
*  @Author: Philipp Pütz
*/

#ifndef _THESEUS_ENGINE_MESSAGE_INTERACT_H
#define _THESEUS_ENGINE_MESSAGE_INTERACT_H

namespace theseus
{	
	namespace gameobjects {
		class Player;
	}

	namespace messages {
		class Interact 
		{
		private:
			theseus::gameobjects::Player * player;
			
		public:
			
			~Interact();

			void setPlayer(theseus::gameobjects::Player * player);

			theseus::gameobjects::Player * getPlayer() const;

		};
	}
}
#include "../gameobjects/player.hpp"
#endif

