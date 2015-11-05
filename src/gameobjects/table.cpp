/*
* @author Dominic Steinhauser, Philipp Pütz
*/
#include "table.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>
#include <cassert>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

const int HORIZONTAL = 0;
const int VERTICAL = 1;

Table::Table(sf::Vector2f position, int tableType) {

	assert(tableType >= 0 && tableType <= 1);
	this->setType(tableType);

	// position
	setPosition(position);

}

void Table::setType(int tableType) {

	this->tableType = tableType;
	sf::Vector2f topLeft(0, 0);
	sf::Vector2f bottomRight;

	switch (tableType) {
	case HORIZONTAL: setTexture(2, TextureManager::instance().getTexture("item_table.png"));
		bottomRight = sf::Vector2f(34, 50);
		break;
	case VERTICAL: setTexture(2, TextureManager::instance().getTexture("item_table2.png"));
		bottomRight = sf::Vector2f(39, 45);
		break;
	}

	this->setCollisionAreaTopLeft(topLeft);
	this->setCollisionAreaBottomRight(bottomRight);
}

Table::~Table() {
}
