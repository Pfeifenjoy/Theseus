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

HealthBar::HealthBar(sf::Vector2f position) {

	// texture
	sf::Texture * texture = &TextureManager::instance().getTexture("heart.png");
	setTexture(4, *texture);
	texture->setRepeated(true);

	MessageReceiver<theseus::messages::UpdateLifePoints>::evOnMessageReceived.subscribe(std::bind(&HealthBar::setHealthPoints, this, _1));

	this->sprite(4).setTextureRect(sf::IntRect(0, 0, 0, 0));
	
	// position
	setPosition(position);


}

void HealthBar::setHealthPoints(const theseus::messages::UpdateLifePoints& message) {

	this->sprite(4).setTextureRect(sf::IntRect(0, 0, IMAGEWIDTH * message.getLifePoints(), IMAGEHEIGTH));

}



HealthBar::~HealthBar() {
}
