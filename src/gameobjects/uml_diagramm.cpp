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
	setCollisionAreaTopLeft(sf::Vector2f(0, 0));
	setCollisionAreaBottomRight(sf::Vector2f(15, 20));



}

UMLDiagramm::~UMLDiagramm() {
}
