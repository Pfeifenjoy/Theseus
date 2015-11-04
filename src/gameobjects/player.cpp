/**
 *  @Author: Tobias Dorra, Leon Mutschke, Dominic Steinhauser
 */


#include "player.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;


Player::Player()
{
	evOnUpdate.subscribe(bind(&Player::onUpdate, this, _1));

	// texture
	setTexture(2, TextureManager::instance().getTexture("player.png"));

}

void Player::onUpdate(float)
{
	sf::Vector2i direction(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		direction.x -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		direction.x += 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		direction.y -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		direction.y += 1;
	setDirection(direction);
}



Player::~Player()
{}

