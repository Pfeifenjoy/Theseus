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

	this->exmatriculationProcess = EXMATRICULATION_VALUE;
	this->exmatricualtionProcessActive = false;

	// Subscribe for Exmatriculation message
	MessageReceiver<Exmatriculation>::evOnMessageReceived.subscribe(std::bind(&Student::exmatriculation, this, _1));

}

Student::~Student() {

}

void Student::exmatriculation(const theseus::messages::Exmatriculation& message) {
	exmatricualtionProcessActive = EXMATRICULATION_TIME;
	// exmatriculationProcess -= 
	// Show Processbar

	if (exmatriculationProcess <= 0) {
		exmatriculationProcess = EXMATRICULATION_VALUE;
		exmatriculationDone();
	}
}

void Student::exmatriculationDone() {

}

