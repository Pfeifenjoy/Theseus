/**
*  @Author: Philipp Pütz
*/

#include <SFML/Graphics.hpp>
#include "../gameobjects/student.hpp"

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;
using namespace theseus::messages;

const float EXMATRICULATION_VALUE = 100;
const float EXMATRICULATION_TIME = 2;

Student::Student() {

	this->exmatriculationProgress = EXMATRICULATION_VALUE;
	this->exmatricualtionProcessActive = EXMATRICULATION_TIME;
	
	exmatriculationDone();

	// Subscribe for Exmatriculation message
	MessageReceiver<Exmatriculation>::evOnMessageReceived.subscribe(std::bind(&Student::exmatriculation, this, _1));
	
	// subscribe for update
	evOnUpdate.subscribe(bind(&Student::onUpdate, this, _1));
}

Student::~Student() {

}

void Student::onUpdate(float timePassed) {
	if (exmatricualtionProcessActive - timePassed > 0) {
		exmatricualtionProcessActive -= timePassed;
	}
	else {
		// Reset timers
		exmatriculationProgress = EXMATRICULATION_VALUE;
		exmatricualtionProcessActive = EXMATRICULATION_TIME;

		// Disable Progressbar
	}
}

void Student::exmatriculation(const theseus::messages::Exmatriculation& message) {
	exmatricualtionProcessActive = EXMATRICULATION_TIME;
	exmatriculationProgress -= message.getExmatriculationAmount();
	professorSendedExmatriculationMessage = message.getProfessorSended();
	// Show Progressbar

	if (exmatriculationProgress <= 0) {
		exmatriculationProgress = EXMATRICULATION_VALUE;
		exmatriculationDone();		
	}
}

void Student::exmatriculationDone(){}