/**
* @author Philipp Pütz
*/
#include "menu.hpp"
#include "../engine/game.hpp"
#include "../engine/scene.hpp"
#include "../gameobjects/button.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

using namespace std;
using namespace theseus::engine;
using namespace theseus::gameobjects;
using namespace theseus::engine::components;

Menu::Menu(float width, float height, std::string * menuItems, int numberOfItems)
{

	this->numberOfItems = numberOfItems;
	this->selectedItemIndex = 0;

	for (int i = 0; i < numberOfItems; i++) {
		if (i == 0) {
			unique_ptr<Button> button = unique_ptr<Button>(new Button(menuItems[i], sf::Vector2f(width / 3, height / (numberOfItems + 1) * (1 + i)), sf::Color::Red));
			buttons.push_back(move(button));
			
		}
		else {
			unique_ptr<Button> button = unique_ptr<Button>(new Button(menuItems[i], sf::Vector2f(width / 3, height / (numberOfItems + 1) * (1 + i)), sf::Color::White));
			buttons.push_back(move(button));
		}	
		this->addGameObject(move(buttons[i]));
	}	
}

void Menu::handleKeyDownEvent(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::W && selectedItemIndex < numberOfItems) {
		buttons[selectedItemIndex]->setColor(4, sf::Color::White);
		buttons[++selectedItemIndex]->setColor(4, sf::Color::Red);
	}
	if (key == sf::Keyboard::S && selectedItemIndex > 0) {
		buttons[selectedItemIndex]->setColor(4, sf::Color::White);
		buttons[--selectedItemIndex]->setColor(4, sf::Color::Red);
	}
	cout << "Geht" << endl;
}

Menu::~Menu()
{
}


