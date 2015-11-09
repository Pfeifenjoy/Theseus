/*
* @author Philipp Pütz
*/
#include "itemcounter.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace theseus::gameobjects;
using namespace theseus::engine;


ItemCounter::ItemCounter(sf::Vector2f position, int numberOfItemsToCollect) {
	
	this->numberOfItemsToCollect = numberOfItemsToCollect;
	this->numberOfItems = 0;
	
	string stringItemCounter = to_string(this->numberOfItems) + " / " + to_string(this->numberOfItemsToCollect);


	//Set the text of the item counter ---- edited by Leon Mutschke on 09.11.2015
	setCharSize(4, 30);
	setText(4, stringItemCounter);
	setColor(4, sf::Color::Yellow);
	setStyle(4, sf::Text::Style::Bold);

	// Set the position
	setPosition(position);

	//setTexture(4, TextureManager::instance().getTexture("INSERT TEXTURE HERE"));
	//sprite(4).setPosition(sf::Vector2f(20, 0));

}

// Returns the actual number of items
int ItemCounter::getNumberOfItems() {
	return numberOfItems;
}

// Returns the number of items which should collected
int ItemCounter::getNumberOfItemsToCollect() {
	return numberOfItemsToCollect;
}

// Adds 1 item to the collected item counter
void ItemCounter::incrementCounter() {
	
	if (numberOfItems < numberOfItemsToCollect) {
		numberOfItems++;
		// Update counter
		string stringItemCounter = to_string(this->numberOfItems) + " / " + to_string(this->numberOfItemsToCollect);
		setText(4, stringItemCounter);
	}
}

ItemCounter::~ItemCounter() {
}
