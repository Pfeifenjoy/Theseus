#include "character.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

Character::Character()
{
	setTexture(3, TextureManager::instance().getTexture("demo_character.png"));
	sprite(3).setScale(5,5);
	setFrameSize(sf::Vector2i(8,8));
	setNumberOfFrames(4);
	setFrameRate(7);
	start();
	
	setPosition(sf::Vector2f(10,10));
	
}

Character::~Character()
{}

