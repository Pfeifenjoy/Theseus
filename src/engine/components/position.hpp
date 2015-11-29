/**
 * Autor: Tobias Dorra
 */
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
	/**
	 * The component Position gives the GameObject a position.
	 */
	class Position
	{
	private:
		sf::Vector2f position;
	protected:

		/**
		 * The event evPositionChanged is triggered, when the position
		 * of the game object has changed.
		 */
		Publisher<sf::Vector2f, sf::Vector2f> evPositionChanged; 	// < old position, new position >

	public:

		/**
		 * Returns the position of the game object.
		 */
		sf::Vector2f getPosition() const;

		/**
		 * Changes the position of the game object.
		 */
		void setPosition(const sf::Vector2f& value);

		/**
		 * Moves the position using the given directional vector
		 */
		void setPositionRelative(const sf::Vector2f direction);

		/**
		 * Destructor
		 */
		virtual ~Position();		
	};
}
}
}
#endif
