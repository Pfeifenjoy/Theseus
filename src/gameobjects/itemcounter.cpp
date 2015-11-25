/*
* @author Philipp Pütz
*/
#include "itemcounter.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace theseus::gameobjects;
using namespace theseus::engine;
using namespace std::placeholders;

ItemCounter::ItemCounter(sf::Vector2f position, string itemPictureName) {
	
	// Storing the important value
	this->numberOfItemsToCollect = 0;
	this->numberOfItems = 0;
	
	// Initialises the counter
	string stringItemCounter = to_string(this->numberOfItems) + " / " + to_string(this->numberOfItemsToCollect);
	
	//Set the text of the item counter ---- edited by Leon Mutschke on 09.11.2015
	setCharSize(4, 24);

	
	setText(4, stringItemCounter);
	setColor(4, sf::Color::Yellow);
	setStyle(4, sf::Text::Style::Bold);

	// Sets texture
	setTexture(4, TextureManager::instance().getTexture(itemPictureName));
	
	// Sets a offset to the absolute position!
	this->sprite(4).setPosition(sf::Vector2f(65, 7));

	// Set the absolute position 
	setPosition(position);

	// register for interact message
	MessageReceiver<theseus::messages::UpdateItemCounter>::evOnMessageReceived.subscribe(std::bind(&ItemCounter::updateMyText, this, _1));
}

void ItemCounter::updateMyText(const theseus::messages::UpdateItemCounter& message) {
	// Updates the counter and saves the values
	this->numberOfItemsToCollect = message.getMaxInventoryValue();
	this->numberOfItems = message.getInventoryValue();
	string stringItemCounter = to_string(this->numberOfItems) + " / " + to_string(this->numberOfItemsToCollect);

	setText(4, stringItemCounter);
}


ItemCounter::~ItemCounter() {}
