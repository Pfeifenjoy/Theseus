/*
* @author Philipp Pütz
*/
#include "caffeinelevel.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

CaffeineLevel::CaffeineLevel(sf::Vector2f position) {

	string stringCaffeineLevel = "Koffeinspiegel: 0%";
		
	//Set the text of the item counter ---- edited by Leon Mutschke on 09.11.2015
	setCharSize(4, 22);
	setText(4, stringCaffeineLevel);
	setColor(4, sf::Color::Yellow);
	//setStyle(4, sf::Text::Style::Bold);

	// Set the position
	setPosition(sf::Vector2f(position.x / 2 - getTextWidth(4) / 2, position.y));

	evOnMessageReceived.subscribe(std::bind(&CaffeineLevel::setCaffeineLevel, this, _1));

}

void CaffeineLevel::setCaffeineLevel(const theseus::messages::UpdateCaffeineLevel& message) {
	string stringCaffeineLevel = "Koffeinspiegel: ";
	setText(4, stringCaffeineLevel + to_string(message.getCaffeineLevel()) + "%");
}


CaffeineLevel::~CaffeineLevel() {
}
