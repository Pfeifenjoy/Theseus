#ifndef _THESEUS_ENGINE_COMPONENTS_POSITION_H
#define _THESEUS_ENGINE_COMPONENTS_POSITION_H

#include "../publisher.hpp"
#include <SFML/System.hpp>

namespace theseus
{
namespace engine
{
namespace components
{

	class Position
	{
	private:
		sf::Vector2f position;
	protected:
		Publisher<sf::Vector2f> evPositionChanged;
		void setPosition(const sf::Vector2f&  value);
	public:
		sf::Vector2f getPosition() const;
	};
}
}
}
#endif
