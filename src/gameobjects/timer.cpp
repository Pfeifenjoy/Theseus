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
	char stringTimer[24];
	sprintf(stringTimer, "%02d : %02d ", (int)trunc(this->startTime / 60), (int)round((int)this->startTime % 60));

	//Set the text of the timer
	setCharSize(4, 26);
	setText(4, stringTimer);
	setColor(4, sf::Color::Black);
	setStyle(4, sf::Text::Style::Bold);
	
	// Set the position
	setPosition(position);
}

void Timer::onUpdate(float timePassed) {

	actualTime -= timePassed;
	if (actualTime >= 0) {
		// Updates the timer text
		char stringTimer[24];
		sprintf(stringTimer, "%02d : %02d ", (int)trunc(actualTime / 60), (int)round((int)actualTime % 60));
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
