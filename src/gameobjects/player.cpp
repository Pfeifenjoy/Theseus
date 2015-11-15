/**
 *  @Author: Tobias Dorra, Leon Mutschke, Dominic Steinhauser, Philipp Pütz
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
using namespace theseus::messages;

const float EXMATRICULATION_TIME = 2;

Player::Player(int startCaffeineLevel, int maxCaffeineLevel, int lifePoints, int itemsToCollect)
{
	if (startCaffeineLevel > maxCaffeineLevel) {
		this->caffeineLevel = (float)maxCaffeineLevel;
	}
	else this->caffeineLevel = startCaffeineLevel;

	this->maxCaffeineLevel = maxCaffeineLevel;
	this->lifePoints = lifePoints;
	this->maxInventoryItems = itemsToCollect;
	this->inventoryItem = 0;

	// subscribe for update
	evOnUpdate.subscribe(bind(&Player::onUpdate, this, _1));
	evKeyDown.subscribe(bind(&Player::keyPressed, this, _1));

	// Subscribe for Exmatriculation message
	// MessageReceiver<Exmatriculation>::evOnMessageReceived.subscribe(std::bind(&Player::exmatriculation, this, _1));
	stopIdle();

	// Update the HUD
	updateCaffeineLevel();
	updateItemCounter();
	updateLifePoints();

	// texture
	setMale(genderMale);

	// camera
	view().setCenter(0, 0);

}

void Player::keyPressed(sf::Keyboard::Key key) {
	// Interact message on <E>
	if (key == sf::Keyboard::Key::E) {
		Interact interact;
		interact.setPlayer(this);

		// Vektor/Graphicx workaround
		sf::Vector2f position = this->getPosition();
		MessageSender<Interact>::sendMessage(
			interact, sf::Vector2f(position.x - 25, position.y + 25), sf::Vector2f(position.x + 57, position.y + 75));
	}
}

void Player::setMale(bool male) {
	setTexture(2, TextureManager::instance().getTexture("player.png"));
	if (male == false)
	{
		setTexture(2, TextureManager::instance().getTexture("player_fem.png"));
	}

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
		setSpeedMultiplier(2);
	}
	else setSpeedMultiplier(1.3); // normal speed


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

	// Attrack professors
	Attrack attraction;
	attraction.position = getPosition() + 0.5f * this->getCollisionAreaTopLeft() + 0.5f * this->getCollisionAreaBottomRight();
	attraction.priority = 3;
	MessageSender<Attrack>::sendMessage(attraction, 500, 500);
}

void Player::exmatriculationDone() {
	if (this->lifePoints <= 1) {
		this->lifePoints = 0;
		updateLifePoints();
		//Abort Game - register for scene access
		evUpdateComponentRegistrations.subscribe(std::bind(&Player::endScene, this, _1));
	}
	else 
	{
		this->lifePoints--;
		updateLifePoints();
	}
}

bool Player::exmatriculationTick(const theseus::messages::Exmatriculation& msg)
{
	auto distance = msg.getOrigin() - getPosition();
	if (distance.x * distance.x + distance.y * distance.y < 1024/* 32^2 */)
	{
		if (professorSendedExmatriculationMessage && inventoryItem >= maxInventoryItems)
			evUpdateComponentRegistrations.subscribe(std::bind(&Player::endScene, this, _1));
	}
	return !professorSendedExmatriculationMessage || this->inventoryItem < this->maxInventoryItems;
}

void Player::endScene(Scene& scene) {
	scene.setFinished();
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

void Player::incrementInventoryItemValue() {
	if (this->inventoryItem < this->maxInventoryItems) {
		this->inventoryItem++;
		updateItemCounter();
	}
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

void Player::setMap(theseus::map::Map *map) {
	this->map = map;
}

Player::~Player()
{}

