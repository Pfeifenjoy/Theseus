/**
* @author Philipp Pütz
*/
#include "intro.hpp"
#include "../engine/scene.hpp"
#include "../gameobjects/textfield.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace theseus::engine;
using namespace theseus::gameobjects;
using namespace theseus::engine::components;

string SLIDE_1 = "Herzlich Willkommen beim DHBW-Labyrinth-Spiel!\n\n\n"
"Achtung! An der DHBW gibt es aktuell besondere Vorkommnisse...\n"
"Die Professoren sind wütend und wild geworden! Ein Virus ist aus\n"
"einem Computer ausgebrochen und hat sämtliche Dozenten und \n"
"Professoren infiziert. Diese haben nun ihre offene, freundliche \n"
"und nette Einstellung gegenüber den Studenten verloren und versuchen \n"
"nun alle Studenten zu exmatrikulieren.Bringe ihnen ihre Gegenstände\n"
"/ Dokumente zurück, um sie zu heilen!"
"\n\n\n"
"Beachte, dass DU der einzige bist, der die DHBW retten kann...\n"
"Doch du musst aufpassen, dass die Dozenten bzw.Professoren nicht\n"
"Dich exmatrikulieren! Absolviere alle 6 Level und befrei die Dozenten\n"
"vom dem Virus... Also sei vorsichtig und rette die DHBW...\n\n\n"
"Weiter mit <Leertaste>";

Intro::Intro(int screenWidth, int screenHeigth)
{
	this->screenWidth = screenWidth;
	this->screenHeigth = screenHeigth;

	unique_ptr<Textfield> textfield = unique_ptr<Textfield>(new Textfield(SLIDE_1, sf::Color::White));

	textfield->setCharSize(20);

	// Center the textfield
	textfield->setPosition(sf::Vector2f(screenWidth / 2 - textfield->getTextWidth() / 2, 80));

	this->textfield = textfield.get();
	this->addGameObject(move(textfield));
}

void Intro::handleKeyDownEvent(sf::Keyboard::Key key)
{	
	if (key == sf::Keyboard::Space) {
		cout << "Ich solle mich beenden..." << endl;
	}

}

Intro::~Intro()
{
}


