#include "level-description.hpp"

using namespace std;
using namespace theseus::map;
using namespace theseus::gameobjects;

void LevelDescription::addGameFreeObject(std::unique_ptr<theseus::engine::GameObject> object){
	this->freeObjects.push_back(move(object));
}

void LevelDescription::addGameFreeObjects(std::vector<std::unique_ptr<theseus::engine::GameObject> > objects){
	for (auto& object : objects)
		this->freeObjects.push_back(move(object));
}
