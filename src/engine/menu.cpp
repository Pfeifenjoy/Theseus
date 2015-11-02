/**
* @author Philipp Pütz
*/
#include "menu.hpp"
#include "../engine/game.hpp"
#include "../engine/scene.hpp"
#include "../gameobjects/button.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

using namespace std;
using namespace theseus::engine;
using namespace theseus::gameobjects;
using namespace theseus::engine::components;

Menu::Menu(float width, float height, std::string * menuItems, int numberOfItems)
{

	this->numberOfItems = numberOfItems;

	button = new Button[numberOfItems];

	for (int i = 0; i < numberOfItems; i++) {
		if (i == 0) {
			auto button = unique_ptr<Button>(new Button(menuItems[i], sf::Vector2f(width / 3, height / (numberOfItems + 1) * (1 + i)), sf::Color::Red));
			this->addGameObject(move(button));
		}
		else {
			auto button = unique_ptr<Button>(new Button(menuItems[i], sf::Vector2f(width / 3, height / (numberOfItems + 1) * (1 + i)), sf::Color::White));
			this->addGameObject(move(button));
		}	
	}	
}

Menu::~Menu()
{
}
