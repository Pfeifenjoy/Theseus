/*
* @author Dominic Steinhauser
*/
#include "uml_diagramm.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

UMLDiagramm::UMLDiagramm() {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_level_4_UML.png"));

	//
	setPosition(sf::Vector2f(0, 0));
	setSize(sf::Vector2f(15, 20));

	// register for interact message
	MessageReceiver<theseus::messages::Interact>::evOnMessageReceived.subscribe(std::bind(&UMLDiagramm::updateItem, this, _1));


}

void UMLDiagramm::updateItem(const theseus::messages::Interact& message) {
	message.getPlayer()->incrementInventoryItemValue();
}

UMLDiagramm::~UMLDiagramm() {
}
