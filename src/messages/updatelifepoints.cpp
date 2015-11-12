/**
*  @Author: Philipp Pütz
*/

#include "updatelifepoints.hpp"

using namespace theseus::messages;

void UpdateLifePoints::setLifePoints(int lifePoints) {
	this->lifePoints = lifePoints;
}

int UpdateLifePoints::getLifePoints() const{
	return this->lifePoints;
}
