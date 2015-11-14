#include "level.hpp"

using namespace theseus::map;
using namespace theseus::engine;

sf::Keyboard::Key Level::getLastKey() {
	return this->lastKey;
}

void Level::handleKeyDownEvent(sf::Keyboard::Key key) {
	Scene::handleKeyDownEvent(key);
	lastKey = key;
}
