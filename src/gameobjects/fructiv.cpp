/*
* @author Dominic Steinhauser
*/
#include "fructiv.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

Fructiv::Fructiv() {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_level_6_fructiv.png"));

	setPosition(sf::Vector2f(0, 0));
	setSize(sf::Vector2f(10, 10));

	// register for interact message
	evOnMessageReceived.subscribe(std::bind(&Fructiv::updateItem, this, _1));


}

void Fructiv::updateItem(const theseus::messages::Interact& message) {
	message.getPlayer()->incrementInventoryItemValue();
}

Fructiv::~Fructiv() {
}
