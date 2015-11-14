#include "sprite.hpp"

using namespace theseus::engine::components;

void Sprite::setTexture(int layer, const sf::Texture& texture)
{
	unsetTexture(layer);
	sprites[layer].setTexture(texture);
	addDrawable(layer, &sprites[layer]);
}

void Sprite::unsetTexture(int layer)
{
	removeDrawable(layer, &sprites[layer]);
}

sf::Sprite& Sprite::sprite(int layer)
{
	return sprites[layer];
}

Sprite::~Sprite()
{}
