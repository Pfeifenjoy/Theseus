/*
* @author Dominic Steinhauser
*/
#include "setlx_cup.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

SetlxCup::SetlxCup() {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_level_6_cup.png"));

	setPosition(sf::Vector2f(0, 0));
	setSize(sf::Vector2f(10, 10));

	// register for interact message
	MessageReceiver<theseus::messages::Interact>::evOnMessageReceived.subscribe(std::bind(&SetlxCup::updateItem, this, _1));


}

void SetlxCup::updateItem(const theseus::messages::Interact& message) {
	message.getPlayer()->incrementInventoryItemValue();
	evUpdateComponentRegistrations.subscribe(std::bind(&SetlxCup::removeMySelf, this, _1));
}

void SetlxCup::removeMySelf(Scene& scene) {
	scene.removeGameObject(this);
}

SetlxCup::~SetlxCup() {
}
