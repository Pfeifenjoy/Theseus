/**
*  @Author: Philipp Pütz
*/

#ifndef _THESEUS_MESSAGES_UPDATEITEMCOUNTER_H
#define _THESEUS_MESSAGES_UPDATEITEMCOUNTER_H

namespace theseus
{
	namespace messages {
		class UpdateItemCounter 
		{
		private:
			int inventoryValue;
			int maxInventoryValue;

		public:
			// Sets the amough of inventory items
			void setInventoryValue(int value);

			// Returns the amough of inventory items
			int getInventoryValue() const;
			
			// Sets the maximum amough of inventory items
			void setMaxInventoryValue(int value);
			
			// Returns the maximum amough of inventory items
			int getMaxInventoryValue() const;
		};
	}
}
#endif

