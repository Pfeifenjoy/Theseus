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
	// Generates a new brick object with a position
	assert(brickType >= 0 && brickType <= 14);
	this->setPosition(sf::Vector2f(x * Brick::WIDTH, y * Brick::HEIGHT));
	// Choose the correct brick type
	this->setType(brickType);
}

Brick::~Brick() {}

void Brick::setType(BrickType brickType) {
	// Saves the brick type
	this->brickType = brickType;

	// Saves some basic informations about every brick
	sf::Vector2f size(Brick::WIDTH, Brick::HEIGHT);
	sf::Vector2f topLeft(0, 0);
	sf::Vector2f bottomRight(Brick::WIDTH, Brick::HEIGHT);

	// Needed for calculating the correct size (different brick type have different sizes!)
	const float figureOffset = 30;

	// Chooses the correct type and sets the corresponding texture
	switch (brickType)
	{
	case HORIZONAL:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_horizontal.png"));
		size = sf::Vector2f(Brick::WIDTH,Brick::HEIGHT);
		topLeft = sf::Vector2f(0, figureOffset);
		break;
	case VERTICAL:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_vertical.png"));
		size = sf::Vector2f(Brick::WIDTH - 2*Brick::OFFSET,Brick::HEIGHT);
		sprite(Brick::LAYER).setPosition(sf::Vector2f(Brick::OFFSET,0));
		bottomRight = size;
		break;
	case EDGE_LEFT_TOP:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_edge_left_top.png"));
		size = sf::Vector2f(Brick::WIDTH - Brick::OFFSET,Brick::HEIGHT);
		sprite(Brick::LAYER).setPosition(sf::Vector2f(Brick::OFFSET,0));
		topLeft = sf::Vector2f(0, figureOffset);
		bottomRight = sf::Vector2f(Brick::WIDTH - 2*Brick::OFFSET,Brick::HEIGHT);
		break;
	case EDGE_LEFT_BOTTOM:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_edge_left_bottom.png"));
		size = sf::Vector2f(Brick::WIDTH - Brick::OFFSET,Brick::HEIGHT);
		sprite(Brick::LAYER).setPosition(sf::Vector2f(Brick::OFFSET,0));
		bottomRight = sf::Vector2f(Brick::WIDTH - 2*Brick::OFFSET,Brick::HEIGHT);
		break;
	case EDGE_RIGHT_BOTTOM:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_edge_right_bottom.png"));
		size = sf::Vector2f(Brick::WIDTH - Brick::OFFSET,Brick::HEIGHT);
		bottomRight = sf::Vector2f(Brick::WIDTH - 2*Brick::OFFSET,Brick::HEIGHT);
		break;
	case EDGE_RIGHT_TOP:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_edge_right_top.png"));
		size = sf::Vector2f(Brick::WIDTH - Brick::OFFSET,Brick::HEIGHT);
		bottomRight = sf::Vector2f(Brick::WIDTH - 2*Brick::OFFSET,Brick::HEIGHT);
		topLeft = sf::Vector2f(0, figureOffset);
		break;
	case LEFT_MIDDLE:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_left_middle.png"));
		size = sf::Vector2f(Brick::WIDTH - Brick::OFFSET,Brick::HEIGHT);
		sprite(Brick::LAYER).setPosition(sf::Vector2f(Brick::OFFSET,0));
		bottomRight = sf::Vector2f(Brick::WIDTH - 2*Brick::OFFSET,Brick::HEIGHT);
		break;
	case LEFT_END:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_left_end.png"));
		size = sf::Vector2f(Brick::WIDTH,Brick::HEIGHT);
		topLeft = sf::Vector2f(0, figureOffset);
		bottomRight = sf::Vector2f(Brick::WIDTH - Brick::OFFSET, Brick::HEIGHT);
		break;
	case RIGHT_MIDDLE:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_right_middle.png"));
		size = sf::Vector2f(Brick::WIDTH - Brick::OFFSET,Brick::HEIGHT);
		bottomRight = sf::Vector2f(Brick::WIDTH - 2*Brick::OFFSET,Brick::HEIGHT);
		break;
	case RIGHT_END:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_right_end.png"));
		size = sf::Vector2f(Brick::WIDTH,Brick::HEIGHT);
		bottomRight = sf::Vector2f(Brick::WIDTH - Brick::OFFSET, Brick::HEIGHT);
		topLeft = sf::Vector2f(0, figureOffset);
		break;
	case BOTTOM_END:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_bottom_end.png"));
		size = sf::Vector2f(Brick::WIDTH - 2*Brick::OFFSET,Brick::HEIGHT);
		sprite(Brick::LAYER).setPosition(sf::Vector2f(Brick::OFFSET, 0));
		bottomRight = size;
		break;
	case TOP_END:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_top_end.png"));
		size = sf::Vector2f(Brick::WIDTH - 2*Brick::OFFSET,Brick::HEIGHT);
		sprite(Brick::LAYER).setPosition(sf::Vector2f(Brick::OFFSET, 0));
		topLeft = sf::Vector2f(0, figureOffset);
		bottomRight = size;
		break;
	case CROSS:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_cross.png"));
		size = sf::Vector2f(Brick::WIDTH,Brick::HEIGHT);
		bottomRight = size;
		break;
	case T_CROSS:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_T_cross.png"));
		size = sf::Vector2f(Brick::WIDTH,Brick::HEIGHT);
		topLeft = sf::Vector2f(0, figureOffset);
		bottomRight = size;
		break;
	case T_UPSIDEDOWN_CROSS:
		setTexture(Brick::LAYER, TextureManager::instance().getTexture("wall_T_upsidedown_cross.png"));
		size = sf::Vector2f(Brick::WIDTH,Brick::HEIGHT);
		bottomRight = size;
		break;
	}

	// Setting the collision area
	this->setCollisionAreaTopLeft(topLeft);
	this->setCollisionAreaBottomRight(bottomRight);
	// Sets the texture area to show
	this->sprite(Brick::LAYER).setTextureRect(sf::IntRect( 0, 0, size.x, size.y));
}
