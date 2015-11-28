/**
 * Autor: Tobias Dorra
 */
#include "position.hpp"
#include <SFML/System.hpp>

using namespace theseus::engine::components;

sf::Vector2f Position::getPosition() const
{
	return position;
}

void Position::setPosition(const sf::Vector2f& value)
{
	auto oldValue = position;
	position = value;
	evPositionChanged(oldValue, value);
}

void Position::setPositionRelative(const sf::Vector2f direction)
{
	setPosition(sf::Vector2f(
				position.x + direction.x,
				position.y + direction.y
				));
}

Position::~Position()
{}
