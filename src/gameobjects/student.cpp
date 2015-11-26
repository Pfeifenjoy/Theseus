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

// Amough of points wich will be reduced if the exmatriculation process is active (reduced by small floats)
const float EXMATRICULATION_VALUE = 1;

// Amough of time (in secs) the exmatriculation message have to be received
const float EXMATRICULATION_TIME = 2;

Student::Student() {

	// Setting some important values
	this->exmatriculationProgress = EXMATRICULATION_VALUE;
	this->exmatriculationProcessActive = EXMATRICULATION_TIME;
	this->exmatriculationable = true;
	this->progressbarActive = false;

	// Subscribe for update
	evOnUpdate.subscribe(bind(&Student::onUpdate, this, _1));
	MessageReceiver<Exmatriculation>::evOnMessageReceived.subscribe(std::bind(&Student::exmatriculation, this, _1));
}

Student::~Student() {

}

void Student::onUpdate(float timePassed) {
	// exmatriculationProcessActive will count down to zero 
	if (exmatriculationProcessActive - timePassed > 0) {
		exmatriculationProcessActive -= timePassed;
	}
	else {
		// Reset timers if the student hasn't received a exmatriculation message in the last seconds
		// or he gots exmatriculated
		exmatriculationProgress = EXMATRICULATION_VALUE;
		exmatriculationProcessActive = EXMATRICULATION_TIME;

		// Disable Progressbar
		if (progressbarActive) {
			unsetTexture(3);
			progressbarActive = false;
		}

	}
}

void Student::exmatriculation(const theseus::messages::Exmatriculation& message)
{
	professorSendedExmatriculationMessage = message.getProfessorSended();

	// If actual student is exmaticulateble...
	if (exmatriculationable && exmatriculationTick(message)) {
		// Reset the timer if the student receive a exmatriculation message
		exmatriculationProcessActive = EXMATRICULATION_TIME;

		// Update the progress status
		exmatriculationProgress -= message.getExmatriculationAmount();

		// Show Progressbar
		interruptSay();
		setTexture(3, TextureManager::instance().getTexture("bar.png"));
		sprite(3).setTextureRect(sf::IntRect(0, 0, (int)((exmatriculationProgress / (EXMATRICULATION_VALUE / 100)) / 2), 10));
		sprite(3).setPosition(sf::Vector2f(-9, -10));
		progressbarActive = true;

		if (exmatriculationProgress <= 0) {
			// Reset progress counter
			exmatriculationProgress = EXMATRICULATION_VALUE;
			this->exmatriculationDone();
		}
	}
}

void Student::setExmatriculationable(bool value) {
	exmatriculationable = value;
}

void Student::exmatriculationDone() {}
bool Student::exmatriculationTick(const Exmatriculation&) { return true; }
