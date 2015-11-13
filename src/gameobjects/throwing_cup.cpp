/*
* @author Dominic Steinhauser
*/
#include "throwing_cup.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

ThrowingCup::ThrowingCup() {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_level_6_cup2.png"));

	setPosition(sf::Vector2f(0, 0));
	setSize(sf::Vector2f(10, 10));

	// register for interact message
	evOnMessageReceived.subscribe(std::bind(&ThrowingCup::updateItem, this, _1));


}

void ThrowingCup::updateItem(const theseus::messages::Interact& message) {
	message.getPlayer()->incrementInventoryItemValue();
}

ThrowingCup::~ThrowingCup() {
}
