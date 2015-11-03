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

Apfeltasche::Apfeltasche(sf::Vector2f position) {

	// texture
	setTexture(3, TextureManager::instance().getTexture("item_level_5_appleturnover.png"));

	//position
	setPosition(position);
	


}

Apfeltasche::~Apfeltasche() {
}
