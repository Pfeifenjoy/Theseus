/**
*  @Author: Philipp Pütz
*/

#include "exmatriculation.hpp"

using namespace theseus::messages;

void Exmatriculation::setProfessorSended() {
	this->professorSended = true;
}

bool Exmatriculation::getProfessorSended() const {
	return this->professorSended;
}
Exmatriculation::~Exmatriculation() {}


