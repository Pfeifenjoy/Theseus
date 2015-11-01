#include "brick.hpp"
#include "../../engine/scene.hpp"
#include "../../engine/game.hpp"
#include "../../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <cassert>

using namespace theseus::gameobjects::map;
using namespace theseus::engine;

Brick::Brick(BrickType brickType, sf::Vector2f position, sf::Vector2f size)
{
	assert(brickType >= 0 && brickType <= 14);
	this->brickType = brickType;
	this->size = size;
	this->position = position;
	this->setPosition(position);
	this->setType(brickType);

}

Brick::~Brick() {}

void Brick::setType(BrickType brickType) {
	sf::Texture * texture;
	switch (brickType) {
	case HORIZONAL: texture = &TextureManager::instance().getTexture("wall_horizontal.png");
		break;
	case VERTICAL: texture = &TextureManager::instance().getTexture("wall_vertical.png");
		break;
	case EDGE_LEFT_TOP: texture = &TextureManager::instance().getTexture("wall_edge_left_bottom.png");
		break;
	case EDGE_LEFT_BOTTOM: texture = &TextureManager::instance().getTexture("wall_edge_left_top.png");
		break;
	case EDGE_RIGHT_BOTTOM: texture = &TextureManager::instance().getTexture("wall_edge_right_bottom.png");
		break;
	case EDGE_RIGHT_TOP: texture = &TextureManager::instance().getTexture("wall_edge_right_top.png");
		break;
	case LEFT_MIDDLE: texture = &TextureManager::instance().getTexture("wall_left_middle.png");
		break;
	case LEFT_END: texture = &TextureManager::instance().getTexture("wall_left_end.png");
		break;
	case RIGHT_MIDDLE: texture = &TextureManager::instance().getTexture("wall_right_middle.png");
		break;
	case RIGHT_END: texture = &TextureManager::instance().getTexture("wall_right_end.png");
		break;
	case BOTTOM_END: texture = &TextureManager::instance().getTexture("wall_bottom_end.png");
		break;
	case TOP_END: texture = &TextureManager::instance().getTexture("wall_top_end.png");
		break;
	case CROSS: texture = &TextureManager::instance().getTexture("wall_cross.png");
		break;
	case T_CROSS: texture = &TextureManager::instance().getTexture("wall_T_cross.png");
		break;
	case T_UPSIDEDOWN_CROSS: texture = &TextureManager::instance().getTexture("wall_T_upsidedown_cross.png");
		break;
	default: throw std::invalid_argument("You used a wrong brick type. Use one between 1 - 15 or take a look at the documentation.");
	}
	setTexture(3, *texture);
	texture->setRepeated(true);
	this->sprite(3).setTextureRect(sf::IntRect( 0, 0, size.x, size.y));
}
