/**
* @author Philipp Pütz
*/
#include "menu.hpp"
#include "../engine/game.hpp"
#include "../engine/scene.hpp"
#include "../gameobjects/textfield.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace theseus::engine;
using namespace theseus::gameobjects;
using namespace theseus::engine::components;

Menu::Menu(const std::vector<std::string>& menuItems, std::vector<unique_ptr<Scene> >& scenes, Game * game)
{

	this->numberOfItems = menuItems.size();
	this->scenes = move(scenes);
	this->game = game;
	this->screenWidth = game->getScreenResolution().x;
	this->screenHeigth = game->getScreenResolution().y;

	// Generate Buttons with the provided text
	for (int i = 0; i < numberOfItems; i++) {

		unique_ptr<Textfield>	button = unique_ptr<Textfield>(new Textfield(menuItems[i], sf::Color::White));

		// Center the button
		button->setPosition(sf::Vector2f(screenWidth / 2 - button->getTextWidth() / 2, screenHeigth / (numberOfItems + 2) * (1 + i)));

		buttons.push_back(button.get());
		this->addGameObject(move(button));
	}

	// Select first button
	this->selectedItemIndex = 0;
	buttons[0]->setColor(4, sf::Color::Red);

	unique_ptr<Textfield> infoField = unique_ptr<Textfield>(new Textfield("Verwende <W>, <S> und <Return> um einen Menüeintrag auszuwählen.", sf::Color::White));
	infoField->setCharSize(14);
	infoField->setPosition(sf::Vector2f(screenWidth / 2 - infoField->getTextWidth() / 2, screenHeigth / (numberOfItems + 2) * (1 + numberOfItems)));
	this->addGameObject(move(infoField));
}

void Menu::handleKeyDownEvent(sf::Keyboard::Key key)
{
	// Select Textfield below/above
	if (key == sf::Keyboard::W && (selectedItemIndex - 1) >= 0) {
		buttons[selectedItemIndex]->setColor(4, sf::Color::White);
		buttons[--selectedItemIndex]->setColor(4, sf::Color::Red);
	}
	if (key == sf::Keyboard::S && (selectedItemIndex + 1) < numberOfItems) {
		buttons[selectedItemIndex]->setColor(4, sf::Color::White);
		buttons[++selectedItemIndex]->setColor(4, sf::Color::Red);
	}
	// Check if a entry gets selected
	if (key == sf::Keyboard::Return) {
		// Start new scene
		if (selectedItemIndex < (int) scenes.size()) {
			if (scenes[selectedItemIndex] != nullptr) {
				game->startScene(move(scenes[selectedItemIndex]));
			}
			else {
				game->quitGame();
			}
		}
	}
}

Menu::~Menu()
{
}


