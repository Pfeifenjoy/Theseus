#include "positionable.hpp"

using namespace theseus::engine::components;
using namespace sf;

void Positionable::setSize(Vector2f size) {
	this->size = size;
}

Vector2f Positionable::getSize() {
	return this->size;
}
