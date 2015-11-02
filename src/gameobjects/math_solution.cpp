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

MathSolution::MathSolution(sf::Vector2f position) {

	// texture
	setTexture(3, TextureManager::instance().getTexture("ball.png"));

	// position
	setPosition(position);


}

MathSolution::~MathSolution() {
}
