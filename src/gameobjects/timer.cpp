/*
* @author Philipp Pütz
*/
#include "timer.hpp"
#include "../engine/components/update.hpp"
#include "../engine/components/text.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;


Timer::Timer(sf::Vector2f position, int startTime) {

	this->startTime = (float)startTime;
	this->actualTime = this->startTime;
	this->lastDisplayedTime = this->startTime;

	// Subscribe to update method
	evOnUpdate.subscribe(bind(&Timer::onUpdate, this, _1));

	// Calculates the string which will be displayed
	string stringMinutes = to_string((int)trunc(this->startTime / 60));
	if (stringMinutes.size() == 1) {
		stringMinutes = "0" + stringMinutes;
	}

	string stringSeconds = to_string((int)round((int)this->startTime % 60));
	if (stringSeconds.size() == 1) {
		stringSeconds = "0" + stringSeconds;
	}

	string stringTimer = stringMinutes + " : " + stringSeconds;

	//Set the text of the timer ---- edited by Leon Mutschke on 09.11.2015
	setCharSize(4, 30);
	setText(4, stringTimer);
	setColor(4, sf::Color::Yellow);
	setStyle(4, sf::Text::Style::Bold);
	
	// Set the position
	setPosition(position);
}

void Timer::onUpdate(float timePassed) {

	actualTime -= timePassed;
	if (actualTime >= 0 && lastDisplayedTime - actualTime > 1) {
		// Updates the timer text
		lastDisplayedTime = actualTime;
		string stringMinutes = to_string((int)trunc(this->actualTime / 60));
		if (stringMinutes.size() == 1) {
			stringMinutes = "0" + stringMinutes;
		}

		string stringSeconds = to_string((int)round((int)this->actualTime % 60));
		if (stringSeconds.size() == 1) {
			stringSeconds = "0" + stringSeconds;
		}

		string stringTimer = stringMinutes + " : " + stringSeconds;
		setText(4, stringTimer);
	}
	else {
		//Abort Level
	}
}

float Timer::getActualTime() {
	return actualTime;
}

Timer::~Timer() {
}
