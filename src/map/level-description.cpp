#include "level-description.hpp"

using namespace std;
using namespace theseus::map;
using namespace theseus::gameobjects;

void LevelDescription::addFreeGameObject(unique_ptr<theseus::engine::GameObject> object) {
	this->freeObjects.push_back(move(object));
}

void LevelDescription::addFreeGameObjects(vector<unique_ptr<theseus::engine::GameObject> > objects) {
	for(auto& object: objects)
		this->freeObjects.push_back(move(object));
}
