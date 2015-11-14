/*
* @author Dominic Steinhauser
*/
#include "c_exam.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

CExam::CExam() {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_level_5_exam.png"));

	setPosition(sf::Vector2f(0, 0));
	setSize(sf::Vector2f(40, 30));

	// register for interact message
	MessageReceiver<theseus::messages::Interact>::evOnMessageReceived.subscribe(std::bind(&CExam::updateItem, this, _1));

}

void CExam::updateItem(const theseus::messages::Interact& message) {
	message.getPlayer()->incrementInventoryItemValue();
	selfDestruct();
}

CExam::~CExam() {
}
