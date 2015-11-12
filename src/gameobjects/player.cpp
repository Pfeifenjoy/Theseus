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


Player::Player(int startCaffeineLevel, int maxCaffeineLevel, int lifePoints, int itemsToCollect)
{
	if (startCaffeineLevel > maxCaffeineLevel) {
		this->caffeineLevel = maxCaffeineLevel;
	}
	else this->caffeineLevel = startCaffeineLevel;

	this->maxCaffeineLevel = maxCaffeineLevel;
	this->lifePoints = lifePoints;
	this->maxInventoryItems = itemsToCollect;
	this->inventoryItem = 0;

	// subscribe for update
	evOnUpdate.subscribe(bind(&Player::onUpdate, this, _1));

	// subscribe for exmatriculation
	evOnMessageReceived.subscribe(std::bind(&Player::exmatriculated, this, _1));


	// Update the HUD
	updateCaffeineLevel();
	updateItemCounter();
	updateLifePoints();

	// texture
	setTexture(2, TextureManager::instance().getTexture("player.png"));

	// camera
	view().setCenter(0, 0);

}

void Player::onUpdate(float timePassed)
{	
	// <Space> for more speed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && caffeineLevel > 0 &&
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))) {
		// reduce caffeinelevel
		caffeineLevel -= 5 * timePassed;
		updateCaffeineLevel();
		setSpeedMultiplier(3);
	}
	else setSpeedMultiplier(1); // normal speed

	// Interact message on <E>
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
		Interact interact;
		interact.setPlayer(this);
		MessageSender<Interact>::sendMessage(interact, 16, 16);
	}

	// <WASD> Movings
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
		updateLifePoints();
	}
}

int Player::getLifePoints() {
	return this->lifePoints;
}

void Player::incrementCaffeineLevel(int value) {
	if (this->caffeineLevel + value > maxCaffeineLevel) {
		this->caffeineLevel = maxCaffeineLevel;
	}
	else {
		this->caffeineLevel += value;
	}	
	updateCaffeineLevel();
}


void Player::exmatriculated(const theseus::messages::Exmatriculation& message) {
	if (this->lifePoints <= 1) {
		// Quit Game
	}
	else {
		// Reset position
		this->lifePoints--;
		updateLifePoints();
	}
}

void Player::incrementInventoryItemValue() {
	this->inventoryItem++;
	updateItemCounter();
}

void Player::updateItemCounter() {
	UpdateItemCounter updateItemCounter;
	updateItemCounter.setInventoryValue(inventoryItem);
	updateItemCounter.setMaxInventoryValue(maxInventoryItems);
	MessageSender<UpdateItemCounter>::sendMessage(updateItemCounter, 10000, 10000);
}

void Player::updateCaffeineLevel() {
	UpdateCaffeineLevel updateCaffeineLevel;
	updateCaffeineLevel.setCaffeineLevel((int)round(this->caffeineLevel / (this->maxCaffeineLevel / 100)));
	MessageSender<UpdateCaffeineLevel>::sendMessage(updateCaffeineLevel, 10000, 10000);
}

void Player::updateLifePoints() {
	UpdateLifePoints updateLifePoints;
	updateLifePoints.setLifePoints(this->lifePoints);
	MessageSender<UpdateLifePoints>::sendMessage(updateLifePoints, 10000, 10000);
}

Player::~Player()
{}

