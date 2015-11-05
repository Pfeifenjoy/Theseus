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

CExam::CExam(sf::Vector2f position) {

	// texture
	setTexture(1, TextureManager::instance().getTexture("item_level_5_exam.png"));

	// position
	setPosition(position);


}

CExam::~CExam() {
}
