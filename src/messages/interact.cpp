/**
*  @Author: Philipp Pütz
*/

#include "interact.hpp"

using namespace theseus::messages;

Interact::Interact() {

}

void Interact::setPlayer(theseus::gameobjects::Player * player) {
	this->player = player;
}

theseus::gameobjects::Player * Interact::getPlayer() const{
	return this->player;
}

Interact::~Interact(){}
