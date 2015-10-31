/*
* Philipp Pütz
*/

#include "menu.hpp"
#include "../engine/scene.hpp"
#include "../engine/game.hpp"
#include <SFML/Graphics.hpp>

using namespace theseus::gameobjects;
using namespace theseus::engine;

Menu::Menu(float width, float height, std::string * menuItems, int numberOfItems)
{

	this->numberOfItems = numberOfItems;

	if (!font.loadFromFile("./resources/fonts/arial.ttf"))
	{
		throw std::invalid_argument("Couldn't load font.");
	}

	menu = new sf::Text[numberOfItems];
	if (menu != nullptr) {
		for (int i = 0; i < numberOfItems; i++) {

			menu[i].setFont(font);
			menu[i].setString(menuItems[i]);
			menu[i].setPosition(sf::Vector2f(width / 2, height / (numberOfItems + 1) * (i + 1)));

			// Set selected item to 0 and color it red
			if (i == 0) {
				selectedItemIndex = 0;
				menu[i].setColor(sf::Color::Red);
			}
			else {
				menu[i].setColor(sf::Color::White);
			}
		}
	}
	else {
		throw std::invalid_argument("Couldn't allocate array");
	}

	
}


Menu::~Menu()
{
}

// Todo How to draw the menu
//void Menu::draw(sf::RenderWindow &window)
//{
//	for (int i = 0; i < numberOfItems; i++)
//	{
//		window.draw(menu[i]);
//	}
//}
//
// Some standart functions copyied from the internet ;)
//void Menu::MoveUp()
//{
//	if (selectedItemIndex - 1 >= 0)
//	{
//		menu[selectedItemIndex].setColor(sf::Color::White);
//		selectedItemIndex--;
//		menu[selectedItemIndex].setColor(sf::Color::Red);
//	}
//}
//
//void Menu::MoveDown()
//{
//	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
//	{
//		menu[selectedItemIndex].setColor(sf::Color::White);
//		selectedItemIndex++;
//		menu[selectedItemIndex].setColor(sf::Color::Red);
//	}
//}