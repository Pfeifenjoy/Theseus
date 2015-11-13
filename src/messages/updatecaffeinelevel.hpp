/**
*  @Author: Philipp Pütz
*/

#ifndef _THESEUS_MESSAGE_UPDATECAFFEINELEVEL_H
#define _THESEUS_MESSAGE_UPDATECAFFEINELEVEL_H

namespace theseus
{
	namespace messages {
		class UpdateCaffeineLevel 
		{
		private:
			// Actual caffeinelevel in percentage (!)
			int caffeineLevel = 0;

		public:
			// Sets caffeinelevel in percentage (!)
			void setCaffeineLevel(int level);

			// Gets caffeinelevel in percentage (!)
			int getCaffeineLevel() const;
		};
	}
}
#endif

