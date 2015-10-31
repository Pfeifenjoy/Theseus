#include "wall.hpp"
#include "../engine/scene.hpp"
#include "../engine/game.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>

using namespace theseus::gameobjects;
using namespace theseus::engine;

Wall::Wall(int wallType, sf::Vector2f position, sf::Vector2f size)
{
	
	this->wallType = wallType;
	this->size = size;
	this->position = position;

	// Set position of the wall
	this->setPosition(position);
	
	sf::Texture * texture;

	// Specify the wall type
	switch (wallType) {
	case 1: texture = &TextureManager::instance().getTexture("wall_horizontal.png");
		break;
	case 2: texture = &TextureManager::instance().getTexture("wall_vertical.png");
		break;
	case 3: texture = &TextureManager::instance().getTexture("wall_edge_left_bottom.png");
		break;
	case 4: texture = &TextureManager::instance().getTexture("wall_edge_left_top.png");
		break;
	case 5: texture = &TextureManager::instance().getTexture("wall_edge_right_bottom.png");
		break;
	case 6: texture = &TextureManager::instance().getTexture("wall_edge_right_top.png");
		break;
	case 7: texture = &TextureManager::instance().getTexture("wall_left_middle.png");
		break;
	case 8: texture = &TextureManager::instance().getTexture("wall_left_end.png");
		break;
	case 9: texture = &TextureManager::instance().getTexture("wall_right_middle.png");
		break;
	case 10: texture = &TextureManager::instance().getTexture("wall_right_end.png");
		break;
	case 11: texture = &TextureManager::instance().getTexture("wall_bottom_end.png");
		break;
	case 12: texture = &TextureManager::instance().getTexture("wall_top_end.png");
		break;
	case 13: texture = &TextureManager::instance().getTexture("wall_cross.png");
		break;
	case 14: texture = &TextureManager::instance().getTexture("wall_T_cross.png");
		break;
	case 15: texture = &TextureManager::instance().getTexture("wall_T_upsidedown_cross.png");
		break;
	default: throw std::invalid_argument("You used a wrong wall type. Use one between 1 - 15 or take a look at the documentation.");
	}

	// Set texture
	setTexture(3, *texture);

	// Repeat texture if nessesary
	texture->setRepeated(true);

	//Set size of the wall IntRect(startposition x, startposition y, length x, height y)
	this->sprite(3).setTextureRect(sf::IntRect( 0, 0, size.x, size.y));

}

Wall::~Wall() {}
