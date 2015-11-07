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

	setCollisionAreaTopLeft(sf::Vector2f(0, 0));
	setCollisionAreaBottomRight(sf::Vector2f(10, 10));


}

ThrowingCup::~ThrowingCup() {
}
