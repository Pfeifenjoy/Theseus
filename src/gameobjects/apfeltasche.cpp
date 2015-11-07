/*
* @author Dominic Steinhauser
*/
#include "apfeltasche.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

Apfeltasche::Apfeltasche() {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_level_5_appleturnover.png"));

	setCollisionAreaTopLeft(sf::Vector2f(0, 0));
	setCollisionAreaBottomRight(sf::Vector2f(10, 10));
	


}

Apfeltasche::~Apfeltasche() {
}
