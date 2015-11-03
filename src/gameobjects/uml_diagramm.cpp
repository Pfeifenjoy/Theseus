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

UMLDiagramm::UMLDiagramm(sf::Vector2f position) {

	// texture
	setTexture(3, TextureManager::instance().getTexture("item_level_4_UML.png"));

	// position
	setPosition(position);



}

UMLDiagramm::~UMLDiagramm() {
}
