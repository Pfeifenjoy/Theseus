/*
* @author Dominic Steinhauser
*/
#include "bizagi_cd.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

BizagiCD::BizagiCD(sf::Vector2f position) {

	// texture
	setTexture(3, TextureManager::instance().getTexture("item_level_1_bizagi_cd.png"));

	// position
	setPosition(position);


}

BizagiCD::~BizagiCD() {
}
