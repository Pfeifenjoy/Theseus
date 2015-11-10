/**
*  @Author: Philipp Pütz
*/

#include "updatecaffeinelevel.hpp"

using namespace std;
using namespace theseus::messages;
using namespace theseus::engine;


void UpdateCaffeineLevel::setCaffeineLevel(int lifePoints) {
	this->caffeineLevel = lifePoints;
}

int UpdateCaffeineLevel::getCaffeineLevel() const {
	return this->caffeineLevel;
}