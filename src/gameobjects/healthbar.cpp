/*
* @author Philipp Pütz
*/
#include "healthbar.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>


using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

const int IMAGEWIDTH = 28;
const int IMAGEHEIGTH = 17;

HealthBar::HealthBar(sf::Vector2f position, int healthPoints) {

	this->healthPoints = healthPoints;


	// texture
	sf::Texture * texture = &TextureManager::instance().getTexture("heart.png");
	setTexture(4, *texture);
	texture->setRepeated(true);
		
	this->sprite(4).setTextureRect(sf::IntRect(0, 0, IMAGEWIDTH * healthPoints, IMAGEHEIGTH));	

	// position
	setPosition(position);


}
int HealthBar::getHealthPoints() {
	return healthPoints;
}

void HealthBar::setHealthPoints(int healthPoints) {
	
	this->healthPoints = healthPoints;

	if (healthPoints > 0) {
		this->sprite(4).setTextureRect(sf::IntRect(0, 0, IMAGEWIDTH * healthPoints, IMAGEHEIGTH));
	}
}


void HealthBar::decrementHealthPoints() {
	if (healthPoints > 0) {
		healthPoints--;
		this->sprite(4).setTextureRect(sf::IntRect(0, 0, IMAGEWIDTH * healthPoints, IMAGEHEIGTH));
	}
}

void HealthBar::incrementHealthPoints() {
	healthPoints++;
	this->sprite(4).setTextureRect(sf::IntRect(0, 0, IMAGEWIDTH * healthPoints, IMAGEHEIGTH));
}


HealthBar::~HealthBar() {
}
