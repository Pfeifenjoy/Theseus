/**
*  @Author: Philipp Pütz
*/

#ifndef _THESEUS_MESSAGES_UPDATEITEMCOUNTER_H
#define _THESEUS_MESSAGES_UPDATEITEMCOUNTER_H

#include "../engine/message.hpp"

namespace theseus
{
	namespace messages {
		class UpdateItemCounter : public theseus::engine::Message
		{
		private:
			int inventoryValue;
			int maxInventoryValue;

		public:
			void setInventoryValue(int value);

			int getInventoryValue() const;

			void setMaxInventoryValue(int value);

			int getMaxInventoryValue() const;
		};
	}
}
#endif

