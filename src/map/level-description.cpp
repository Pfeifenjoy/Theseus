#include "level-description.hpp"

using namespace std;
using namespace theseus::map;

void LevelDescription::addFreeGameObject(std::unique_ptr<Positionable> object){
	this->freeObjects.push_back(move(object));
}

void LevelDescription::addFreeGameObjects(std::vector<std::unique_ptr<Positionable> > objects){
	for (auto& object : objects)
		this->freeObjects.push_back(move(object));
}

vector<unique_ptr<Positionable> > LevelDescription::getFreeObjects() {
	return move(this->freeObjects);
}

sf::Vector2f LevelDescription::getDimensions() {
	return this->dimensions;
}
