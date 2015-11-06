#include "room-description.hpp"
#include <cassert>

using namespace theseus::map;
using namespace theseus::engine;
using namespace std;

RoomDescription::RoomDescription(float width, float height) : width(width), height(height) {
	assert(width > 0);
	assert(height > 0);
}

float RoomDescription::getHeight() {
	return this->height;
}
float RoomDescription::getWidth() {
	return this->width;
}

void RoomDescription::addGameObject(unique_ptr<Positionable> gameObject){
	this->gameobjects.push_back(move(gameObject));
}

vector<unique_ptr<Positionable> > RoomDescription::getGameObjects() {
	return move(this->gameobjects);
}
