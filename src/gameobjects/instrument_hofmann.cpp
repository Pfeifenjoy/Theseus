/*
* @author Dominic Steinhauser
*/
#include "instrument_hofmann.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

Instrument::Instrument() {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_level_4_meter.png"));

	setPosition(sf::Vector2f(0, 0));
	setSize(sf::Vector2f(10,15));

	// register for interact message
	MessageReceiver<theseus::messages::Interact>::evOnMessageReceived.subscribe(std::bind(&Instrument::updateItem, this, _1));

}

void Instrument::updateItem(const theseus::messages::Interact& message) {
	message.getPlayer()->incrementInventoryItemValue();
	selfDestruct();
}

Instrument::~Instrument() {
}
