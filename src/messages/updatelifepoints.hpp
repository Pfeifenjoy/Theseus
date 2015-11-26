/**
*  @Author: Philipp Pütz
*/

#ifndef _THESEUS_ENGINE_MESSAGE_UPDATELIFEPOINTS_H
#define _THESEUS_ENGINE_MESSAGE_UPDATELIFEPOINTS_H

namespace theseus
{
	namespace messages {
		class UpdateLifePoints 
		{
		private:
			int lifePoints = 0;

		public:
			// Sets the actual amough of liefpoints
			void setLifePoints(int lifePoints);

			// Returns the acutal amough of lifepoints
			int getLifePoints() const;
		};
	}
}
#endif

