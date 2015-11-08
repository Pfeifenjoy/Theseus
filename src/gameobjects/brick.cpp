/**
*   Author: Philipp Pütz, Arwed Mett
*/
#include "brick.hpp"
#include "../engine/scene.hpp"
#include "../engine/game.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <cassert>

using namespace theseus::gameobjects;
using namespace theseus::engine;

Brick::Brick(BrickType brickType, int x, int y) {
	assert(brickType >= 0 && brickType <= 14);
	this->setPosition(sf::Vector2f(x * Brick::WIDTH, y * Brick::HEIGHT));
	this->setType(brickType);
}

Brick::~Brick() {}

void Brick::setType(BrickType brickType) {
	this->brickType = brickType;
	sf::Vector2f size(Brick::WIDTH, Brick::HEIGHT);
	sf::Vector2f topLeft(0, 0);
	sf::Vector2f bottomRight(32, 64);
	const float figureOffset = 30;
	switch (brickType)
	{
	case HORIZONAL:
		setTexture(2, TextureManager::instance().getTexture("wall_horizontal.png"));
		size = sf::Vector2f(32,64);
		topLeft = sf::Vector2f(0, figureOffset);
		break;
	case VERTICAL:
		setTexture(2, TextureManager::instance().getTexture("wall_vertical.png"));
		size = sf::Vector2f(20,64);
		sprite(2).setPosition(sf::Vector2f(6,0));
		bottomRight = size;
		break;
	case EDGE_LEFT_TOP:
		setTexture(2, TextureManager::instance().getTexture("wall_edge_left_top.png"));
		size = sf::Vector2f(26,64);
		sprite(2).setPosition(sf::Vector2f(6,0));
		topLeft = sf::Vector2f(0, figureOffset);
		bottomRight = sf::Vector2f(20,64);
		break;
	case EDGE_LEFT_BOTTOM:
		setTexture(2, TextureManager::instance().getTexture("wall_edge_left_bottom.png"));
		size = sf::Vector2f(26,64);
		sprite(2).setPosition(sf::Vector2f(6,0));
		bottomRight = sf::Vector2f(20,64);
		break;
	case EDGE_RIGHT_BOTTOM:
		setTexture(2, TextureManager::instance().getTexture("wall_edge_right_bottom.png"));
		size = sf::Vector2f(26,64);
		bottomRight = sf::Vector2f(20,64);
		break;
	case EDGE_RIGHT_TOP:
		setTexture(2, TextureManager::instance().getTexture("wall_edge_right_top.png"));
		size = sf::Vector2f(26,64);
		bottomRight = sf::Vector2f(20,64);
		topLeft = sf::Vector2f(0, figureOffset);
		break;
	case LEFT_MIDDLE:
		setTexture(2, TextureManager::instance().getTexture("wall_left_middle.png"));
		size = sf::Vector2f(26,64);
		sprite(2).setPosition(sf::Vector2f(6,0));
		bottomRight = sf::Vector2f(20,64);
		break;
	case LEFT_END:
		setTexture(2, TextureManager::instance().getTexture("wall_left_end.png"));
		size = sf::Vector2f(32,64);
		topLeft = sf::Vector2f(0, figureOffset);
		bottomRight = sf::Vector2f(26, 64);
		break;
	case RIGHT_MIDDLE:
		setTexture(2, TextureManager::instance().getTexture("wall_right_middle.png"));
		size = sf::Vector2f(26,64);
		bottomRight = sf::Vector2f(20,64);
		break;
	case RIGHT_END:
		setTexture(2, TextureManager::instance().getTexture("wall_right_end.png"));
		size = sf::Vector2f(32,64);
		bottomRight = sf::Vector2f(26, 64);
		topLeft = sf::Vector2f(0, figureOffset);
		break;
	case BOTTOM_END:
		setTexture(2, TextureManager::instance().getTexture("wall_bottom_end.png"));
		size = sf::Vector2f(20,64);
		sprite(2).setPosition(sf::Vector2f(6, 0));
		bottomRight = size;
		break;
	case TOP_END:
		setTexture(2, TextureManager::instance().getTexture("wall_top_end.png"));
		size = sf::Vector2f(20,64);
		sprite(2).setPosition(sf::Vector2f(6, 0));
		topLeft = sf::Vector2f(0, figureOffset);
		bottomRight = size;
		break;
	case CROSS:
		setTexture(2, TextureManager::instance().getTexture("wall_cross.png"));
		size = sf::Vector2f(32,64);
		bottomRight = size;
		break;
	case T_CROSS:
		setTexture(2, TextureManager::instance().getTexture("wall_T_cross.png"));
		size = sf::Vector2f(32,64);
		topLeft = sf::Vector2f(0, figureOffset);
		bottomRight = size;
		break;
	case T_UPSIDEDOWN_CROSS:
		setTexture(2, TextureManager::instance().getTexture("wall_T_upsidedown_cross.png"));
		size = sf::Vector2f(32,64);
		bottomRight = size;
		break;
	}

	this->setCollisionAreaTopLeft(topLeft);
	this->setCollisionAreaBottomRight(bottomRight);
	this->sprite(2).setTextureRect(sf::IntRect( 0, 0, size.x, size.y));
	//this->sprite(2).getTexture()->isRepeated();
}
