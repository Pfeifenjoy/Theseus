/**
*  @Author: Philipp Pütz
*/

#include <SFML/Graphics.hpp>
#include "../engine/texturemanager.hpp"
#include "../gameobjects/student.hpp"
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;
using namespace theseus::messages;

const float EXMATRICULATION_VALUE = 100;
const float EXMATRICULATION_TIME = 2;

Student::Student() {

	this->exmatriculationProgress = EXMATRICULATION_VALUE;
	this->exmatriculationProcessActive = EXMATRICULATION_TIME;
	this->exmatriculationable = true;
	this->progressbarActive = false;

	// subscribe for update
	evOnUpdate.subscribe(bind(&Student::onUpdate, this, _1));
}

Student::~Student() {

}

void Student::onUpdate(float timePassed) {
	if (exmatriculationProcessActive - timePassed > 0) {
		exmatriculationProcessActive -= timePassed;
	}
	else {
		// Reset timers
		exmatriculationProgress = EXMATRICULATION_VALUE;
		exmatriculationProcessActive = EXMATRICULATION_TIME;

		// Disable Progressbar
		if (progressbarActive) {
			sprite(3).setTextureRect(sf::IntRect(0, 0, 0, 0));
			progressbarActive = false;
		}

	}
}

void Student::exmatriculation(const theseus::messages::Exmatriculation& message) {
	if (exmatriculationable) {
		exmatriculationProcessActive = EXMATRICULATION_TIME;
		//exmatriculationProgress -= message.setExmatriculationAmount;
		exmatriculationProgress -= 1.5;

		professorSendedExmatriculationMessage = message.getProfessorSended();

		// Show Progressbar
		setTexture(3, TextureManager::instance().getTexture("bar.png"));
		sprite(3).setTextureRect(sf::IntRect(0, 0, (int)round(exmatriculationProgress / (EXMATRICULATION_VALUE / 100)) / 2, 10));
		sprite(3).setPosition(sf::Vector2f(-9, -10));
		progressbarActive = true;

		if (exmatriculationProgress <= 0) {
			exmatriculationProgress = EXMATRICULATION_VALUE;
			this->exmatriculationDone();
		}
	}
}

void Student::setExmatriculationable(bool value) {
	exmatriculationable = value;
}

void Student::exmatriculationDone() {}