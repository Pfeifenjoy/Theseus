/*
* @author Philipp Pütz
*/
#include "caffeinelevel.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;
using namespace theseus::gameobjects;
using namespace theseus::engine;


CaffeineLevel::CaffeineLevel(sf::Vector2f position, float startLevel, float maximumLevel) {

	if (startLevel > maximumLevel) {
		this->startLevel = maximumLevel;
	}
	else {
		this->startLevel = startLevel;
	}
	this->maximumLevel = maximumLevel;
	this->actualLevel = this->startLevel;

	string stringCaffeineLevel = "Koffeinspiegel: " + to_string((int) round(this->actualLevel / (this->maximumLevel / 100))) + "%";

	//Set the text of the item counter ---- edited by Leon Mutschke on 09.11.2015
	setCharSize(4, 22);
	setText(4, stringCaffeineLevel);
	setColor(4, sf::Color::Yellow);
	//setStyle(4, sf::Text::Style::Bold);

	// Set the position
	setPosition(sf::Vector2f(position.x / 2 - getTextWidth(4) / 2, position.y));

}

// Returns the actual caffeine level
float CaffeineLevel::getActualLevel() {
	return this->actualLevel;
}

// Returns the maximum caffeine level
float CaffeineLevel::getMaximumLevel() {
	return this->maximumLevel;
}

// Decrements the caffeine level by a certan amough of points
void CaffeineLevel::decrementCaffeineLevel(float points) {

	if (actualLevel - points < 0) {
		actualLevel = 0;
	}
	else {
		actualLevel -= points;
	}

	string stringCaffeineLevel = "Koffeinspiegel: " + to_string((int) round(this->actualLevel / (this->maximumLevel / 100))) + "%";

	setText(4, stringCaffeineLevel);
}

// Increments the caffeine level by a certan amough of points
void CaffeineLevel::incrementCaffeineLevel(float points) {

	if (actualLevel + points > maximumLevel) {
		actualLevel = maximumLevel;
	}
	else {
		actualLevel += points;
	}

	string stringCaffeineLevel = "Koffeinspiegel: " + to_string((int) round(this->actualLevel / (this->maximumLevel / 100))) + "%";

	setText(4, stringCaffeineLevel);
}

CaffeineLevel::~CaffeineLevel() {
}
