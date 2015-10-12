#ifndef _THESEUS_ENGINE_COMPONENTS_SPEED_H
#define _THESEUS_ENGINE_COMPONENTS_SPEED_H 

#include "update.hpp"
#include "position.hpp"
#include "../subscription.hpp"
#include <SFML/System.hpp>

namespace theseus
{
namespace engine
{
namespace components
{

	class Speed
		: public virtual Update
		, public virtual Position
	{
	private:
		Subscription<float> update;
		void onUpdate(float timePassed);
		
		sf::Vector2f speed;

	public:
		Speed();

		void setSpeed(sf::Vector2f value);
		sf::Vector2f getSpeed() const;
	};

}
}
}

#endif
