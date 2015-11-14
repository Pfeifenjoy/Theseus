/**
* @author Leon Mutschke
*/
#include "characterselection.hpp"
#include "../engine/game.hpp"
#include "../engine/scene.hpp"
#include "../gameobjects/textfield.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cassert>

using namespace std;
using namespace theseus::scenes;
using namespace theseus::gameobjects;
using namespace theseus::engine::components;

const sf::Color& ACTIVE_BUTTON_CHARACTER = sf::Color::Red;
const sf::Color& INACTIVE_BUTTON_CHARACTER = sf::Color::White;
const int BUTTON_LAYER_CHARACTER = 4;

CharacterSelection::CharacterSelection(const std::vector<std::string>& scenes, theseus::engine::Game* game)
{

	this->screenWidth = game->getScreenResolution().x;
	this->screenHeigth = game->getScreenResolution().y;

	int numberOfItems = (int)scenes.size();
	// Generate Buttons with the provided text
	int i;
	for (i = 0; i < (int)scenes.size(); i++) {

		unique_ptr<Textfield>	button(new Textfield(scenes[i], sf::Color::White));

		// Center the button
		button->setPosition(sf::Vector2f(screenWidth / 2 - button->getTextWidth() / 2, screenHeigth / (scenes.size() + 2) * (1 + i)));

		buttons.push_back(button.get());
		this->addGameObject(move(button));
	}

	// Select first button
	this->setSelectedItemIndex(0);
	this->updateSelection();

	unique_ptr<Textfield> infoField = unique_ptr<Textfield>(new Textfield("Verwende <W>, <S> und <Return> um einen Charakter auszuwaehlen.", sf::Color::White));
	infoField->setCharSize(14);
	infoField->setPosition(sf::Vector2f(screenWidth / 2 - infoField->getTextWidth() / 2, screenHeigth / (numberOfItems + 2) * (1 + numberOfItems)));
	this->addGameObject(move(infoField));
}

void CharacterSelection::handleKeyDownEvent(sf::Keyboard::Key key)
{
	this->lastKeyEvent = key;
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

void CharacterSelection::setSelectedItemIndex(short i) {
	if (i < 0) i = 0;
	if (i >= (short) this->buttons.size()) i = this->buttons.size() - 1;
	this->selectedItemIndex = i;
	this->updateSelection();
}

void CharacterSelection::updateSelection() {
	for (auto& button : this->buttons) {
		button->setColor(BUTTON_LAYER_CHARACTER, INACTIVE_BUTTON_CHARACTER);
	}
	this->buttons[selectedItemIndex]->setColor(BUTTON_LAYER_CHARACTER, ACTIVE_BUTTON_CHARACTER);
}

short CharacterSelection::getSelectedItemIndex() {
	return this->selectedItemIndex;
}

sf::Keyboard::Key CharacterSelection::getLastKeyEvent() {
	return this->lastKeyEvent;
}



CharacterSelection::~CharacterSelection()
{
}


