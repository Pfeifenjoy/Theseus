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
	this->size = sf::Vector2f(32,64);
	this->setPosition(position);
	this->setType(brickType);

}

Brick::~Brick() {}

void Brick::setType(BrickType brickType) {
	switch (brickType)
	{
	case HORIZONAL:
		setTexture(3, TextureManager::instance().getTexture("wall_horizontal.png"));
		this->size = sf::Vector2f(32,64);
		break;
	case VERTICAL:
		setTexture(3, TextureManager::instance().getTexture("wall_vertical.png"));
		this->size = sf::Vector2f(20,64);
		sprite(3).setPosition(sf::Vector2f(5,0));
		break;
	case EDGE_LEFT_TOP:
		setTexture(3, TextureManager::instance().getTexture("wall_edge_left_top.png"));
		this->size = sf::Vector2f(32,64);
		break;
	case EDGE_LEFT_BOTTOM:
		setTexture(3, TextureManager::instance().getTexture("wall_edge_left_bottom.png"));
		this->size = sf::Vector2f(32,64);
		break;
	case EDGE_RIGHT_BOTTOM:
		setTexture(3, TextureManager::instance().getTexture("wall_edge_right_bottom.png"));
		this->size = sf::Vector2f(32,64);
		break;
	case EDGE_RIGHT_TOP:
		setTexture(3, TextureManager::instance().getTexture("wall_edge_right_top.png"));
		this->size = sf::Vector2f(32,64);
		break;
	case LEFT_MIDDLE:
		setTexture(3, TextureManager::instance().getTexture("wall_left_middle.png"));
		this->size = sf::Vector2f(32,64);
		break;
	case LEFT_END:
		setTexture(3, TextureManager::instance().getTexture("wall_left_end.png"));
		this->size = sf::Vector2f(32,64);
		break;
	case RIGHT_MIDDLE:
		setTexture(3, TextureManager::instance().getTexture("wall_right_middle.png"));
		this->size = sf::Vector2f(32,64);
		break;
	case RIGHT_END:
		setTexture(3, TextureManager::instance().getTexture("wall_right_end.png"));
		this->size = sf::Vector2f(32,64);
		break;
	case BOTTOM_END:
		setTexture(3, TextureManager::instance().getTexture("wall_bottom_end.png"));
		this->size = sf::Vector2f(20,64);
		break;
	case TOP_END:
		setTexture(3, TextureManager::instance().getTexture("wall_top_end.png"));
		this->size = sf::Vector2f(20,20);
		break;
	case CROSS:
		setTexture(3, TextureManager::instance().getTexture("wall_cross.png"));
		this->size = sf::Vector2f(32,64);
		break;
	case T_CROSS:
		setTexture(3, TextureManager::instance().getTexture("wall_T_cross.png"));
		this->size = sf::Vector2f(32,64);
		break;
	case T_UPSIDEDOWN_CROSS:
		setTexture(3, TextureManager::instance().getTexture("wall_T_upsidedown_cross.png"));
		this->size = sf::Vector2f(32,64);
		break;
	}

	this->sprite(3).setTextureRect(sf::IntRect( 0, 0, size.x, size.y));
	this->sprite(3).getTexture()->isRepeated();
}
