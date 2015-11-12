/**
*  @Author: Philipp P�tz
*/

#include "updateitemcounter.hpp"

using namespace theseus::messages;

void UpdateItemCounter::setInventoryValue(int value) {
	this->inventoryValue = value;
}

int UpdateItemCounter::getInventoryValue() const {
	return this->inventoryValue;
}

void UpdateItemCounter::setMaxInventoryValue(int value) {
	this->maxInventoryValue = value;
}

int UpdateItemCounter::getMaxInventoryValue() const {
	return this->maxInventoryValue;
}
