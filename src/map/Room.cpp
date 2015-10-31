#include "Room.hpp"

using namespace theseus::map;
using namespace std;

void Room::addGameObject(engine::GameObject gameObject){
	this->gameobjects.push_back(gameObject);
}
