/*
* @author Dominic Steinhauser
*/
#include "instrument_hofmann.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

Instrument::Instrument(sf::Vector2f position) {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_level_4_meter.png"));

	// position
	setPosition(position);


}

Instrument::~Instrument() {
}
