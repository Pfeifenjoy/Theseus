#include "level-description.hpp"
#include <cassert>

using namespace std;
using namespace theseus::map;

void LevelDescription::addFreeGameObject(std::unique_ptr<theseus::engine::components::Positionable> object){
	this->freeObjects.push_back(move(object));
}

void LevelDescription::addFreeGameObjects(std::vector<std::unique_ptr<theseus::engine::components::Positionable> > objects){
	for (auto& object : objects)
		this->freeObjects.push_back(move(object));
}

vector<unique_ptr<theseus::engine::components::Positionable> > LevelDescription::getFreeObjects() {
	return move(this->freeObjects);
}

vector<unique_ptr<RoomDescription> > LevelDescription::getRooms() {
	return move(this->rooms);
}

void LevelDescription::addRoom(unique_ptr<RoomDescription> room) {
	this->rooms.push_back(move(room));
}

void LevelDescription::setMinRoomSize(sf::Vector2f size) {
	assert(this->maxRoomSize.x >= size.x);
	assert(this->maxRoomSize.y >= size.y);
	this->minRoomSize = size;
}

void LevelDescription::setMaxRoomSize(sf::Vector2f size) {
	assert(this->minRoomSize.x <= size.x);
	assert(this->minRoomSize.y <= size.y);
	this->maxRoomSize = size;
}

void LevelDescription::setMaxAmountOfStandardRooms(int amount) {
	this->maxAmountOfStandardRooms = amount;
}

sf::Vector2f LevelDescription::getMinRoomSize() {
	return this->minRoomSize;
}

sf::Vector2f LevelDescription::getMaxRoomSize() {
	return this->maxRoomSize;
}

int LevelDescription::getMaxAmountOfStandardRooms() {
	return this->maxAmountOfStandardRooms;
}

sf::Vector2f LevelDescription::getDimensions() {
	return this->dimensions;
}

void LevelDescription::setPlayer(unique_ptr<theseus::gameobjects::Player> player) {
	this->player = move(player);
}

unique_ptr<theseus::gameobjects::Player> LevelDescription::getPlayer() {
	return move(this->player);
}

void LevelDescription::setProf(unique_ptr<theseus::engine::components::Seaker> prof) {
	this->prof = move(prof);
}

unique_ptr<theseus::engine::components::Seaker> LevelDescription::getProf() {
	return move(this->prof);
}

