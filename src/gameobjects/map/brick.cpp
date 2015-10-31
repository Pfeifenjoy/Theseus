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

	// Set position of the brick
	this->setPosition(position);

	sf::Texture * texture;

	// Specify the brick type
	switch (brickType) {
	case HORIZONAL: texture = &TextureManager::instance().getTexture("brick_horizontal.png");
		break;
	case VERTICAL: texture = &TextureManager::instance().getTexture("brick_vertical.png");
		break;
	case EDGE_LEFT_TOP: texture = &TextureManager::instance().getTexture("brick_edge_left_bottom.png");
		break;
	case EDGE_LEFT_BOTTOM: texture = &TextureManager::instance().getTexture("brick_edge_left_top.png");
		break;
	case EDGE_RIGHT_BOTTOM: texture = &TextureManager::instance().getTexture("brick_edge_right_bottom.png");
		break;
	case EDGE_RIGHT_TOP: texture = &TextureManager::instance().getTexture("brick_edge_right_top.png");
		break;
	case LEFT_MIDDLE: texture = &TextureManager::instance().getTexture("brick_left_middle.png");
		break;
	case LEFT_END: texture = &TextureManager::instance().getTexture("brick_left_end.png");
		break;
	case RIGHT_MIDDLE: texture = &TextureManager::instance().getTexture("brick_right_middle.png");
		break;
	case RIGHT_END: texture = &TextureManager::instance().getTexture("brick_right_end.png");
		break;
	case BOTTOM_END: texture = &TextureManager::instance().getTexture("brick_bottom_end.png");
		break;
	case TOP_END: texture = &TextureManager::instance().getTexture("brick_top_end.png");
		break;
	case CROSS: texture = &TextureManager::instance().getTexture("brick_cross.png");
		break;
	case T_CROSS: texture = &TextureManager::instance().getTexture("brick_T_cross.png");
		break;
	case T_UPSIDEDOWN_CROSS: texture = &TextureManager::instance().getTexture("brick_T_upsidedown_cross.png");
		break;
	default: throw std::invalid_argument("You used a wrong brick type. Use one between 1 - 15 or take a look at the documentation.");
	}

	// Set texture
	setTexture(3, *texture);

	// Repeat texture if nessesary
	texture->setRepeated(true);

	//Set size of the brick IntRect(startposition x, startposition y, length x, height y)
	this->sprite(3).setTextureRect(sf::IntRect( 0, 0, size.x, size.y));

}

Brick::~Brick() {}
