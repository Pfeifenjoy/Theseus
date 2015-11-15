/**
* @author Dominic Steinhauser
*/
#include "highscore.hpp"
#include "../engine/scene.hpp"
#include "../gameobjects/textfield.hpp"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace theseus::engine;
using namespace theseus::scenes;
using namespace theseus::gameobjects;
using namespace theseus::engine::components;


string HEADING = "Urkunde";
string CONCRAT = "Herzlichen Glueckwunsch";
string FAIL = "Das Studium wurde leider nicht bestanden...";


Highscore::Highscore(int screenWidth, int screenHeigth, float time)
{
	this->screenWidth = screenWidth;
	this->screenHeigth = screenHeigth;

	unique_ptr<Textfield> heading = unique_ptr<Textfield>(new Textfield(HEADING, sf::Color::White));
	unique_ptr<Textfield> textfield = unique_ptr<Textfield>(new Textfield("Deine Abschlussnote " + getHighscore(time), sf::Color::White));
	unique_ptr<Textfield> concrats;

	if (time != 0) {
		concrats = unique_ptr<Textfield>(new Textfield(CONCRAT, sf::Color::White));
	}
	else {
		concrats = unique_ptr<Textfield>(new Textfield(FAIL, sf::Color::White));
	}



	heading->setCharSize(80);
	textfield->setCharSize(40);


	// Center the textfield
	textfield->setPosition(sf::Vector2f(screenWidth / 2 - textfield->getTextWidth() / 2, 240));
	heading->setPosition(sf::Vector2f(screenWidth / 2 - heading->getTextWidth() / 2, 80));
	concrats->setPosition(sf::Vector2f(screenWidth / 2 - concrats->getTextWidth() / 2, 320));

	this->textfield = textfield.get();
	this->addGameObject(move(textfield));
	this->addGameObject(move(heading));
	this->addGameObject(move(concrats));
}

void Highscore::handleKeyDownEvent(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Space) {
		this->finished = true;
	}

}

string Highscore::getHighscore(float timeLeft)
{
	string mark;
	// if at least 3 minutes after completing the last level are remaining, then you get an 1,0. otherwise the mark rises by 0.5 every 30 seconds
	if (timeLeft >= 180) {
		mark = "1.0";
		return mark;
	}
	else if (timeLeft >= 150 && timeLeft < 180) {
		mark = "1.5";
		return mark;
	}
	else if (timeLeft >= 120 && timeLeft < 150) {
		mark = "2,0";
		return mark;
	}
	else if (timeLeft >= 90 && timeLeft < 120) {
		mark = "2.5";
		return mark;
	}
	else if (timeLeft >= 60 && timeLeft < 90) {
		mark = "3.0";
		return mark;
	}
	else if (timeLeft >= 30 && timeLeft < 60) {
		mark = "3.5";
		return mark;
	}
	else if (timeLeft > 0 && timeLeft < 30) {
		mark = "4.0";
		return mark;
	}
	else {
		mark = "5.0";
		return mark;
	}
}

Highscore::~Highscore()
{
}


