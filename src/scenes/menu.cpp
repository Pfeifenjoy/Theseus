/**
* @author Philipp Pütz, Arwed Mett
*/
#include "menu.hpp"
#include "../engine/scene.hpp"
#include "../gameobjects/textfield.hpp"
#include <SFML/Graphics.hpp>
#include <cassert>

using namespace std;
using namespace theseus::scenes;
using namespace theseus::gameobjects;
using namespace theseus::engine::components;

const sf::Color& ACTIVE_BUTTON = sf::Color::Red;
const sf::Color& INACTIVE_BUTTON = sf::Color::White;
const int BUTTON_LAYER = 4;

Menu::Menu(const std::vector<std::string>& scenes, int screenWidth, int screenHeigth)
{

	this->screenWidth = screenWidth;
	this->screenHeigth = screenHeigth;

	int numberOfItems = (int)scenes.size();

	// Generate Buttons with the provided text
	for (int i = 0; i < (int)scenes.size(); i++) {

		unique_ptr<Textfield>	button(new Textfield(scenes[i], sf::Color::White));

		// Center the button
		button->setPosition(sf::Vector2f(screenWidth / 2 - button->getTextWidth() / 2, screenHeigth / (scenes.size() + 2) * (1 + i)));

		// Add the button to the vector
		buttons.push_back(button.get());
		this->addGameObject(move(button));
	}

	// Select first button
	this->setSelectedItemIndex(0);
	this->updateSelection();

	// Set info text
	unique_ptr<Textfield> infoField = unique_ptr<Textfield>(new Textfield("Verwende <W>, <S> und <Return> um einen Menueeintrag auszuwaehlen.", sf::Color::White));
	infoField->setCharSize(14);
	infoField->setPosition(sf::Vector2f(screenWidth / 2 - infoField->getTextWidth() / 2, screenHeigth / (numberOfItems + 2) * (1 + numberOfItems)));
	this->addGameObject(move(infoField));
}

void Menu::handleKeyDownEvent(sf::Keyboard::Key key)
{
	// Select Textfield below/above
	if (key == sf::Keyboard::W) {
		this->setSelectedItemIndex(selectedItemIndex - 1);
		this->updateSelection();
	}
	if (key == sf::Keyboard::S) {
		this->setSelectedItemIndex(selectedItemIndex + 1);
		this->updateSelection();
	}
	// Check if a entry gets selected
	if (key == sf::Keyboard::Return || key == sf::Keyboard::Escape) {
		this->finished = true;
	}

}

void Menu::setSelectedItemIndex(short i) {
	// Check if selection is correct
	if (i < 0) i = 0;
	if (i >= (short) this->buttons.size()) i = this->buttons.size() - 1;
	this->selectedItemIndex = i;
	this->updateSelection();
}

void Menu::updateSelection() {
	// Change selected menu item color
	for (auto& button : this->buttons) {
		button->setColor(BUTTON_LAYER, INACTIVE_BUTTON);
	}
	this->buttons[selectedItemIndex]->setColor(BUTTON_LAYER, ACTIVE_BUTTON);
}

short Menu::getSelectedItemIndex() {
	return this->selectedItemIndex;
}




Menu::~Menu()
{
}


