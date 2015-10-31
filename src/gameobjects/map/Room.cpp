#include "Room.hpp"

using namespace theseus::gameobjects::map;
using namespace std;

void Room::addGameObject(shared_ptr<engine::GameObject> gameObject){
	this->gameobjects.push_back(gameObject);
}
