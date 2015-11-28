/**
 * Autor: Tobias Dorra
 */
#ifndef _THESEUS_ENGINE_COMPONENTS_SPEED_H
#define _THESEUS_ENGINE_COMPONENTS_SPEED_H 

#include "update.hpp"
#include "position.hpp"
#include <SFML/System.hpp>

namespace theseus
{
namespace engine
{
namespace components
{
	/**
	 * Gives the game object a speed and automatically adjusts its position accordingly on the update event. 
	 */
	class Speed
		: public virtual Update
		, public virtual Position
	{
	private:
		void onUpdate(float timePassed);
		
		sf::Vector2f speed;

	protected:

		void setSpeed(sf::Vector2f value);

	public:

		Speed();
		virtual ~Speed();
		sf::Vector2f getSpeed() const;
	};

}
}
}

#endif
