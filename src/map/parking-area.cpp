#include "parking-area.hpp"
#include <iostream>

using namespace theseus::gameobjects;
using namespace theseus::map;
using namespace std;

ParkingArea::ParkingArea(sf::Vector2f position, sf::Vector2<int> size) {
	int x = size.x / 100;
	int y = size.y / 100;
	int i, j;
	cout << x << ", " << y << endl;
	for(i = 0; i < x - 1; i++) {
		for(j = 0; j < y; j++) {
			unique_ptr<ParkingSlot> slot(new ParkingSlot(ParkingSlot::LEFT, 100, 100));
			slot->setPosition(sf::Vector2f (position.x + 100 * i, position.y + 100 * j));
			this->slots.push_back(move(slot));
		}
	}
	for(j = 0; j < y; j++) {
		unique_ptr<ParkingSlot> slot(new ParkingSlot(ParkingSlot::RIGHT, 100, 100));
		slot->setPosition(sf::Vector2f (position.x + 100 * (x - 1), position.y + 100 * j));
		this->slots.push_back(move(slot));
	}
}

vector<unique_ptr<ParkingSlot> > ParkingArea::getSlots() {
	return move(this->slots);
}

ParkingArea::~ParkingArea() {}
