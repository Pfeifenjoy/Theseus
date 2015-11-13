/*
* @author Dominic Steinhauser
*/
#include "coffee.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

const int CAFFEINEVALUE = 25;

Coffee::Coffee() {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_coffee.png"));

	setPosition(sf::Vector2f(0, 0));
	setSize(sf::Vector2f(10, 10));

	// register for interact event
	MessageReceiver<theseus::messages::Interact>::evOnMessageReceived.subscribe(std::bind(&Coffee::incrementCaffeineLevel, this, _1));

}


void Coffee::incrementCaffeineLevel(const theseus::messages::Interact& message) {
	message.getPlayer()->incrementCaffeineLevel(CAFFEINEVALUE);
	//evUpdateComponentRegistrations.subscribe(bind(&Coffee::removeMySelf, this, _1));

}
void Coffee::removeMySelf(Scene& scene) {
	//scene.removeGameObject(this);
}


Coffee::~Coffee() {
}
