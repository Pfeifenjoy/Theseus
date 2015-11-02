/*
* @author Dominic Steinhauser
*/
#include "table.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

Table::Table(sf::Vector2f position) {

	// texture
	setTexture(3, TextureManager::instance().getTexture("ball.png"));

	// position
	setPosition(position);


}

Table::~Table() {
}
