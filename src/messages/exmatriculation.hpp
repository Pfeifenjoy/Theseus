/**
*  @Author: Philipp Pütz
*/

#ifndef _THESEUS_MESSAGES_EXMATRICULATION_H
#define _THESEUS_MESSAGES_EXMATRICULATION_H

#include "../engine/message.hpp"

namespace theseus
{
	namespace messages {
		class Exmatriculation : public theseus::engine::Message
		{
		public:
			Exmatriculation();

			~Exmatriculation();

		};
	}
}
#endif

