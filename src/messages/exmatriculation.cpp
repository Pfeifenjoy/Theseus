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

void Exmatriculation::setOrigin(sf::Vector2f value)
{
	origin = value;
}

sf::Vector2f Exmatriculation::getOrigin() const
{
	return origin;
}
				
Exmatriculation::~Exmatriculation() {}


