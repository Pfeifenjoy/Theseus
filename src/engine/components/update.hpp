#ifndef _THESEUS_ENGINE_COMPONENTS_UPDATE_H
#define _THESEUS_ENGINE_COMPONENTS_UPDATE_H

#include "base.hpp"
#include "../publisher.hpp"

namespace theseus
{
namespace engine
{

class Scene;

namespace components
{
	class Update
		: public virtual Base
	{
	private:
		void onRegisterComponents(Scene& scene);
		void onUnregisterComponents(Scene& scene);

	protected:
		Publisher<float> evOnUpdate; 	// parameter: passed time in seconds 
	public:
		Update();
		virtual ~Update();
		void doUpdate(float passedTime);
	};
}
}
}

#endif
