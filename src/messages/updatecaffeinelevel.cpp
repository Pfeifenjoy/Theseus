/**
*  @Author: Philipp P�tz
*/

#include "updatecaffeinelevel.hpp"

using namespace theseus::messages;

void UpdateCaffeineLevel::setCaffeineLevel(int lifePoints) {
	this->caffeineLevel = lifePoints;
}

int UpdateCaffeineLevel::getCaffeineLevel() const {
	return this->caffeineLevel;
}
