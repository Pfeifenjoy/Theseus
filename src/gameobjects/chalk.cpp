/*
* @author Dominic Steinhauser
*/
#include "chalk.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

Chalk::Chalk() {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_level_2_chalk.png"));

	setPosition(sf::Vector2f(0, 0));
	setSize(sf::Vector2f(10, 10));


}

Chalk::~Chalk() {
}
