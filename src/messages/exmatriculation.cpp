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

void Exmatriculation::setExmatriculationAmount(float value)
{
	exmatriculationAmount = value;
}

float Exmatriculation::getExmatriculationAmount() const
{
	return exmatriculationAmount;
}

Exmatriculation::~Exmatriculation() {}


