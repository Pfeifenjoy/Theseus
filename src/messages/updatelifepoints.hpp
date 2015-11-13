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
			void setLifePoints(int lifePoints);

			int getLifePoints() const;
		};
	}
}
#endif

