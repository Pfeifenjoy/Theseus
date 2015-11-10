/**
*  @Author: Philipp Pütz
*/

#include "updatelifepoints.hpp"

using namespace std;
using namespace theseus::messages;
using namespace theseus::engine;


void UpdateLifePoints::setLifePoints(int lifePoints) {
	this->lifePoints = lifePoints;
}

int UpdateLifePoints::getLifePoints() const{
	return this->lifePoints;
}