/**
*   Author: Leon Mutschke, Philipp Pütz
*/

#include "floor.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

Floor::Floor(sf::Vector2f position, sf::Vector2f size, FloorType type) {

	// texture


	//position
	setPosition(position);

	sf::Texture *texture;
	switch(type) {
		case CORRIDOR: texture = &TextureManager::instance().getTexture("floor_black.png"); break;
		case ROOM: texture = &TextureManager::instance().getTexture("floor_red.png"); break;
	}

	setTexture(0,*texture);

	// Repeat texture if nessesary
	texture->setRepeated(true);

	//Set size of the wall IntRect(startposition x, startposition y, length x, height y)
	this->sprite(0).setTextureRect(sf::IntRect(0, 0, size.x, size.y));


}

Floor::~Floor() {
}
