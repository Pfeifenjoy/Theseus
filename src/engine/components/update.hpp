#ifndef _THESEUS_ENGINE_COMPONENTS_UPDATE_H
#define _THESEUS_ENGINE_COMPONENTS_UPDATE_H

#include "base.hpp"
#include "../publisher.hpp"
#include "../subscription.hpp"

namespace theseus
{
namespace engine
{
namespace components
{
	class Update
		: public virtual Base
	{
	private:

		Subscription<> baseInitialized;
		void onBaseInitialized();

	public:
		Update();
		Publisher<float> evOnUpdate; 	// parameter: passed time in seconds 
	};
}
}
}

#endif
