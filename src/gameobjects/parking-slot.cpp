#include "parking-slot.hpp"
#include "../engine/texturemanager.hpp"
#include "../engine/game.hpp"
#include <SFML/Graphics.hpp>

using namespace theseus::gameobjects;
using namespace theseus::engine;
using namespace std;

ParkingSlot::ParkingSlot(int type, int width, int height) {
	if(height / width == 0) {
		if(type == ParkingSlot::LEFT) {
			this->setTexture(1, TextureManager::instance().getTexture("parking_area_double.png"));
		} else {
			this->setTexture(1, TextureManager::instance().getTexture("parking_area_double.png"));
		}
	} else {
		if(type == ParkingSlot::LEFT) {
			this->setTexture(1, TextureManager::instance().getTexture("parking_area.png"));
		} else {
			this->setTexture(1, TextureManager::instance().getTexture("parking_area.png"));
		}
	}

	this->sprite(1).setTextureRect(sf::IntRect (0, 0, width, height));
}

ParkingSlot::~ParkingSlot() {}
