#include "sprite.hpp"

using namespace theseus::engine::components;

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	auto pos = getPosition();
	mysprite.setPosition(pos);
	target.draw(mysprite, states);
}

void Sprite::setTexture(const sf::Texture& texture)
{
	mysprite.setTexture(texture);
}

sf::Sprite& Sprite::sprite()
{
	return mysprite;
}
