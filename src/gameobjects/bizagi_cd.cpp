/*
* @author Dominic Steinhauser
*/
#include "bizagi_cd.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

BizagiCD::BizagiCD() {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_level_1_bizagi_cd.png"));
	setPosition(sf::Vector2f(0,0));
	setSize(sf::Vector2f(10, 10));

	// register for interact message
	evOnMessageReceived.subscribe(std::bind(&BizagiCD::updateItem, this, _1));

}

void BizagiCD::updateItem(const theseus::messages::Interact& message) {
	message.getPlayer()->incrementInventoryItemValue();
}

BizagiCD::~BizagiCD() {
}
