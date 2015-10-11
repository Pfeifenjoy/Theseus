#include "position.hpp"
#include <SFML/System.hpp>

using namespace theseus::engine::components;

sf::Vector2f Position::getPosition() const
{
	return position;
}

void Position::setPosition(const sf::Vector2f& value)
{
	position = value;
	evPositionChanged(value);
}
