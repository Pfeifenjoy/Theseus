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

Fructiv::Fructiv(sf::Vector2f position) {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_level_6_fructiv.png"));

	// position
	setPosition(position);


}

Fructiv::~Fructiv() {
}
