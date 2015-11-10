/**
*  @Author: Philipp Pütz
*/

#ifndef _THESEUS_ENGINE_MESSAGE_INTERACT_H
#define _THESEUS_ENGINE_MESSAGE_INTERACT_H

#include "../engine/message.hpp"

namespace theseus
{
	namespace messages {
		class Interact : public theseus::engine::Message
		{
		private:
			
		public:
			Interact();

			~Interact();

		};
	}
}
#endif

