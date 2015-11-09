/*
* @author Dominic Steinhauser
*/
#include "math_solution.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

MathSolution::MathSolution() {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_level_3_solutions.png"));

	setPosition(sf::Vector2f(0, 0));
	setSize(sf::Vector2f(15, 20));


}

MathSolution::~MathSolution() {
}
