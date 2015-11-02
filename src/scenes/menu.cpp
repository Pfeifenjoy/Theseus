/**
* @author Philipp Pütz
*/
#include "menu.hpp"
#include "../engine/game.hpp"
#include "../engine/scene.hpp"
#include "../gameobjects/button.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace theseus::engine;
using namespace theseus::gameobjects;
using namespace theseus::engine::components;

// ToDo: exit menu / start last scene / quit program

Menu::Menu(float width, float height, const std::vector<std::string>& menuItems, std::vector<unique_ptr<Scene> >& scenes, Game * game)
{

	this->numberOfItems = menuItems.size();
	this->scenes = move(scenes);
	this->game = game;

	// Generate Buttons with the provided text
	for (int i = 0; i < numberOfItems; i++)
	{
		unique_ptr<Button>	button = unique_ptr<Button>(new Button(menuItems[i], sf::Vector2f(width / 3, height / (numberOfItems + 1) * (1 + i)), sf::Color::White));

		buttons.push_back(button.get());
		this->addGameObject(move(button));

	}

	// Select first button
	this->selectedItemIndex = 0;
	buttons[0]->setColor(4, sf::Color::Red);
}

void Menu::handleKeyDownEvent(sf::Keyboard::Key key)
{
	// Select Button below/above
	if (key == sf::Keyboard::W && (selectedItemIndex - 1) >= 0) {
		buttons[selectedItemIndex]->setColor(4, sf::Color::White);
		buttons[--selectedItemIndex]->setColor(4, sf::Color::Red);
	}
	if (key == sf::Keyboard::S && (selectedItemIndex + 1) < numberOfItems) {
		buttons[selectedItemIndex]->setColor(4, sf::Color::White);
		buttons[++selectedItemIndex]->setColor(4, sf::Color::Red);
	}
	if (key == sf::Keyboard::Return) {
		// Start new scene
		game->startScene(move(scenes[selectedItemIndex]));
	}

}


Menu::~Menu()
{
}


