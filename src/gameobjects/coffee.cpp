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

Coffee::Coffee() {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_coffee.png"));

	setCollisionAreaTopLeft(sf::Vector2f(0, 0));
	setCollisionAreaBottomRight(sf::Vector2f(10, 10));


}

Coffee::~Coffee() {
}
