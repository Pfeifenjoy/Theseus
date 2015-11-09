/**
* @author Dominic Steinhauser
*/
#include "highscore.hpp"
#include "../engine/scene.hpp"
#include "../gameobjects/textfield.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace theseus::engine;
using namespace theseus::gameobjects;
using namespace theseus::engine::components;

string mark = "224";
//string SLIDE_1 = "Deine Abschlussnote: " + mark;

Highscore::Highscore(int screenWidth, int screenHeigth)
{
	this->screenWidth = screenWidth;
	this->screenHeigth = screenHeigth;

	unique_ptr<Textfield> textfield = unique_ptr<Textfield>(new Textfield(mark, sf::Color::White));

	textfield->setCharSize(20);

	// Center the textfield
	textfield->setPosition(sf::Vector2f(screenWidth / 2 - textfield->getTextWidth() / 2, 80));

	this->textfield = textfield.get();
	this->addGameObject(move(textfield));
}

void Highscore::handleKeyDownEvent(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Space) {
		cout << "Ich solle mich beenden..." << endl;
	}

}

string Highscore::getHighscore(float timeLeft)
{
	if (timeLeft > 10 && timeLeft < 100) {
		return mark;
	}
	else {
		return mark;
	}
}

Highscore::~Highscore()
{
}


