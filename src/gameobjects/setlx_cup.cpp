/*
* @author Dominic Steinhauser
*/
#include "setlx_cup.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

SetlxCup::SetlxCup(sf::Vector2f position) {

	// texture
	setTexture(3, TextureManager::instance().getTexture("item_level_6_cup.png"));

	// position
	setPosition(position);


}

SetlxCup::~SetlxCup() {
}
