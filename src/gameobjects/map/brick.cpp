#include "brick.hpp"
#include "../../engine/scene.hpp"
#include "../../engine/game.hpp"
#include "../../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <cassert>

using namespace theseus::gameobjects::map;
using namespace theseus::engine;

Brick::Brick(BrickType brickType, int x, int y) {
	assert(brickType >= 0 && brickType <= 14);
	this->setPosition(sf::Vector2f(x * Brick::WIDTH, y * Brick::HEIGHT));
	this->setType(brickType);
	this->setCollisionAreaTopLeft(sf::Vector2f (0, 0));
	this->setCollisionAreaBottomRight(sf::Vector2f ( 32, 64 ));
}

Brick::~Brick() {}

void Brick::setType(BrickType brickType) {
	this->brickType = brickType;
	sf::Vector2f size(Brick::WIDTH, Brick::HEIGHT);
	switch (brickType)
	{
	case HORIZONAL:
		setTexture(3, TextureManager::instance().getTexture("wall_horizontal.png"));
		size = sf::Vector2f(32,64);
		break;
	case VERTICAL:
		setTexture(3, TextureManager::instance().getTexture("wall_vertical.png"));
		size = sf::Vector2f(20,64);
		sprite(3).setPosition(sf::Vector2f(6,0));
		break;
	case EDGE_LEFT_TOP:
		setTexture(3, TextureManager::instance().getTexture("wall_edge_left_top.png"));
		size = sf::Vector2f(26,64);
		sprite(3).setPosition(sf::Vector2f(6,0));
		break;
	case EDGE_LEFT_BOTTOM:
		setTexture(3, TextureManager::instance().getTexture("wall_edge_left_bottom.png"));
		size = sf::Vector2f(26,64);
		sprite(3).setPosition(sf::Vector2f(6,0));
		break;
	case EDGE_RIGHT_BOTTOM:
		setTexture(3, TextureManager::instance().getTexture("wall_edge_right_bottom.png"));
		size = sf::Vector2f(26,64);
		break;
	case EDGE_RIGHT_TOP:
		setTexture(3, TextureManager::instance().getTexture("wall_edge_right_top.png"));
		size = sf::Vector2f(26,64);
		break;
	case LEFT_MIDDLE:
		setTexture(3, TextureManager::instance().getTexture("wall_left_middle.png"));
		size = sf::Vector2f(26,64);
		sprite(3).setPosition(sf::Vector2f(6,0));
		break;
	case LEFT_END:
		setTexture(3, TextureManager::instance().getTexture("wall_left_end.png"));
		size = sf::Vector2f(32,64);
		break;
	case RIGHT_MIDDLE:
		setTexture(3, TextureManager::instance().getTexture("wall_right_middle.png"));
		size = sf::Vector2f(26,64);
		break;
	case RIGHT_END:
		setTexture(3, TextureManager::instance().getTexture("wall_right_end.png"));
		size = sf::Vector2f(32,64);
		break;
	case BOTTOM_END:
		setTexture(3, TextureManager::instance().getTexture("wall_bottom_end.png"));
		size = sf::Vector2f(20,64);
		sprite(3).setPosition(sf::Vector2f(6, 0));
		break;
	case TOP_END:
		setTexture(3, TextureManager::instance().getTexture("wall_top_end.png"));
		size = sf::Vector2f(20,64);
		sprite(3).setPosition(sf::Vector2f(6, 0));
		//sprite(3).setScale(1, 3.2);
		break;
	case CROSS:
		setTexture(3, TextureManager::instance().getTexture("wall_cross.png"));
		size = sf::Vector2f(32,64);
		break;
	case T_CROSS:
		setTexture(3, TextureManager::instance().getTexture("wall_T_cross.png"));
		size = sf::Vector2f(32,64);
		break;
	case T_UPSIDEDOWN_CROSS:
		setTexture(3, TextureManager::instance().getTexture("wall_T_upsidedown_cross.png"));
		size = sf::Vector2f(32,64);
		break;
	}

	this->sprite(3).setTextureRect(sf::IntRect( 0, 0, size.x, size.y));
	//this->sprite(3).getTexture()->isRepeated();
}
