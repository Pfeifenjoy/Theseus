/**
 *  @Author: Tobias Dorra, Leon Mutschke, Dominic Steinhauser, Philipp Pütz
 */

#include "player.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>
#include <iostream>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;
using namespace theseus::messages;


Player::Player(int startCaffeineLevel, int maxCaffeineLevel, int lifePoints)
{
	if (startCaffeineLevel > maxCaffeineLevel) {
		this->caffeineLevel = maxCaffeineLevel;
	}
	else this->caffeineLevel = startCaffeineLevel;

	this->maxCaffeineLevel = maxCaffeineLevel;
	this->lifePoints = lifePoints;

	evOnUpdate.subscribe(bind(&Player::onUpdate, this, _1));

	// texture
	setTexture(2, TextureManager::instance().getTexture("player.png"));

	// camera
	view().setCenter(0, 0);

}

void Player::onUpdate(float timePassed)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && caffeineLevel > 0 &&
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))) {
		caffeineLevel -= 5 * timePassed;
		setSpeedMultiplier(3);
	}
	else setSpeedMultiplier(1); // normal speed


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

void Player::decrementLifePoints() {
	if (this->lifePoints > 0) {
		this->lifePoints--;
		UpdateLifePoints updateLifePoints;
		updateLifePoints.setLifePoints(this->lifePoints);
		sendMessage(updateLifePoints, 10000, 10000);
	}
}

int Player::getLifePoints() {
	return this->lifePoints;
}


Player::~Player()
{}

