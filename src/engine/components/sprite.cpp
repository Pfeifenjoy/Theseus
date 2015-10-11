#include "sprite.hpp"

using namespace theseus::engine::components;

void Sprite::setTexture(int layer, const sf::Texture& texture)
{
	sprites[layer].setTexture(texture);
	setDrawableOnLayer(layer, &sprites[layer]);
}

sf::Sprite& Sprite::sprite(int layer)
{
	return sprites[layer];
}
