#ifndef _THESEUS_ENGINE_COMPONENTS_POSITION_H
#define _THESEUS_ENGINE_COMPONENTS_POSITION_H

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
	public:
		sf::Vector2f getPosition() const;
		void setPosition(const sf::Vector2f&  value);
	};
}
}
}
#endif
