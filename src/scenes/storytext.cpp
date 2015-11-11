/**
* @author Philipp Pütz, Leon Mutschke, Dominic Steinhauser
*/
#include "storytext.hpp"
#include "../engine/scene.hpp"
#include "../gameobjects/textfield.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace theseus::engine;
using namespace theseus::scenes;
using namespace theseus::gameobjects;
using namespace theseus::engine::components;



StoryText::StoryText(int screenWidth, int screenHeigth, string storyText)
{
	this->screenWidth = screenWidth;
	this->screenHeigth = screenHeigth;

	unique_ptr<Textfield> textfield = unique_ptr<Textfield>(new Textfield(storyText, sf::Color::White));

	textfield->setCharSize(20);

	// Center the textfield
	textfield->setPosition(sf::Vector2f(screenWidth / 2 - textfield->getTextWidth() / 2, 80));

	//this->textfield = textfield.get();
	this->addGameObject(move(textfield));
}

void StoryText::handleKeyDownEvent(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Space) {
		this->finished = true;
	}
}

StoryText::~StoryText()
{
}


