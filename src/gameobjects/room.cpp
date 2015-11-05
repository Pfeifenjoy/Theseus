#include "room.hpp"
#include "../engine/texturemanager.hpp"

using namespace std;
using namespace theseus::engine;
using namespace theseus::gameobjects;

Room::Room(sf::Vector2f position, sf::Vector2f size) {

	sf::Texture *texture;

	texture = &TextureManager::instance().getTexture("floor_red.png");
	setTexture(0, *texture);

	// Repeat texture if nessesary
	texture->setRepeated(true);

	//Set size of the wall IntRect(startposition x, startposition y, length x, height y)
	this->sprite(0).setTextureRect(sf::IntRect(0, 0, size.x, size.y));

}

Room::~Room() {}
