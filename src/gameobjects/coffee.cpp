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

Coffee::Coffee(sf::Vector2f position) {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_coffee.png"));

	// position
	setPosition(position);


}

Coffee::~Coffee() {
}
