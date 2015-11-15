#include "character.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

const float SPEED = 100.;
const float SPEED_DIAGONAL = 70.71; 	// SPEED / sqrt(2)
const int PLAYER_W = 32;
const int PLAYER_H = 50;

Character::Character()
{
	// animation
	setAnimatedLayer(2);
	setFrameSize(sf::Vector2i(PLAYER_W, PLAYER_H));
	setNumberOfFrames(4);
	setFrameRate(7);

	// walking
	setDirection(sf::Vector2i(0, 0), true);

	// speed settings
	this->speedMultiplier = 1;

	// Settings for autoplacement during levelgeneration
	this->setSize(sf::Vector2f(22, 50));

	// Collision detection
	this->setCollisionAreaTopLeft(sf::Vector2f(0, 40));
	this->setCollisionAreaBottomRight(this->getSize());
	this->evCollisionDetected.subscribe(bind(&Character::onCollision, this, _1));

	// Speech bubble
	sprite(3).setPosition(20, -30);
	text(3).setColor(sf::Color::Black);
	text(3).setCharacterSize(16);
	text(3).setPosition(25, -18);
	evOnUpdate.subscribe(bind(&Character::onUpdate, this, _1));
}


void Character::setDirection(sf::Vector2i d, bool force_update)
{

	if (d == sf::Vector2i(0, 0))			setSpeed(sf::Vector2f(0, 0));
	else if (d == sf::Vector2i(0, 1))		setSpeed(sf::Vector2f(0, SPEED * speedMultiplier));
	else if (d == sf::Vector2i(0, -1))		setSpeed(sf::Vector2f(0, -SPEED * speedMultiplier));
	else if (d == sf::Vector2i(1, 0))		setSpeed(sf::Vector2f(SPEED * speedMultiplier, 0));
	else if (d == sf::Vector2i(1, 1))   	setSpeed(sf::Vector2f(SPEED_DIAGONAL * speedMultiplier, SPEED_DIAGONAL * speedMultiplier));
	else if (d == sf::Vector2i(1, -1))		setSpeed(sf::Vector2f(SPEED_DIAGONAL * speedMultiplier, -SPEED_DIAGONAL * speedMultiplier));
	else if (d == sf::Vector2i(-1, 0))		setSpeed(sf::Vector2f(-SPEED * speedMultiplier, 0));
	else if (d == sf::Vector2i(-1, 1))		setSpeed(sf::Vector2f(-SPEED_DIAGONAL * speedMultiplier, SPEED_DIAGONAL * speedMultiplier));
	else if (d == sf::Vector2i(-1, -1))		setSpeed(sf::Vector2f(-SPEED_DIAGONAL * speedMultiplier, -SPEED_DIAGONAL * speedMultiplier));

	// making changes to the animation will reset it to continue at the first frame.
	// this is why we must only update it when the direction really has changed.
	// Otherwise the animation would be resetted to the first frame on every update,
	// which would make it quite boring.
	if (d == direction && !force_update)
		return;

	direction = d;

	if (d == sf::Vector2i(0, 1))		setFirstFramePosition(sf::Vector2i(0, 0));
	else if (d == sf::Vector2i(0, -1))	setFirstFramePosition(sf::Vector2i(0, 3 * PLAYER_H));
	else if (d == sf::Vector2i(1, 0))	setFirstFramePosition(sf::Vector2i(0, 2 * PLAYER_H));
	else if (d == sf::Vector2i(1, 1))	setFirstFramePosition(sf::Vector2i(0, 4 * PLAYER_H));
	else if (d == sf::Vector2i(1, -1))	setFirstFramePosition(sf::Vector2i(0, 6 * PLAYER_H));
	else if (d == sf::Vector2i(-1, 0))	setFirstFramePosition(sf::Vector2i(0, PLAYER_H));
	else if (d == sf::Vector2i(-1, 1))	setFirstFramePosition(sf::Vector2i(0, 5 * PLAYER_H));
	else if (d == sf::Vector2i(-1, -1))	setFirstFramePosition(sf::Vector2i(0, 7 * PLAYER_H));

	if (d == sf::Vector2i(0, 0))
	{
		seek(0);
		pause();
	}
	else
	{
		start();
	}
}

void Character::setSpeedMultiplier(float value) {
	this->speedMultiplier = value;
}

void Character::say(std::string text, float duration)
{
	setTexture(3, TextureManager::instance().getTexture("speech_bubble.png"));	
	setText(3, text);
	remainingSpeechBubbleTime = duration;
}
		
void Character::startAutoSpeech(const std::vector<std::string>& sentences, float duration, float minPause, float maxPause, bool loop, bool shuffle)
{
	as_sentences = sentences;
	as_duration = duration;
	as_minPause = minPause;
	as_pauseRandomLength = maxPause - minPause;
	as_loop = loop;
	as_shuffle = shuffle;
	as_position = as_sentences.begin();
	as_active = true;
	as_currentPause = as_minPause + (float)(rand() % (int)(as_pauseRandomLength * 100)) / 100;
}

void Character::onUpdate(float timePassed)
{
	// update speech bubble visibility
	if (remainingSpeechBubbleTime < timePassed & 0 <= remainingSpeechBubbleTime)
	{
		unsetText(3);
		unsetTexture(3);
	}
	remainingSpeechBubbleTime -= timePassed;

	// update autospeech
	if (as_active && remainingSpeechBubbleTime < -as_currentPause)
	{
		// show next speech bubble
		if (as_shuffle && as_position == as_sentences.begin())
		{
			std::random_shuffle(as_sentences.begin(), as_sentences.end());	
		}
		say(*as_position, as_duration);
		as_currentPause = as_minPause + (float)(rand() % (int)(as_pauseRandomLength * 100)) / 100;
		++as_position;
		if (as_position == as_sentences.end())
		{
			as_position = as_sentences.begin();
			as_active = as_loop;
		}
	}

	// update IDLEing
	if (idleActive)
	{
		directionTimeout -= timePassed;
		if (directionTimeout < 0)
		{
			directionTimeout = 2;
			changeDirection();
		}
	}
}

void Character::changeDirection()
{
	sf::Vector2i direction(0, 0);
	int number = rand() % 9;

	switch (number)
	{
		case 0: direction = sf::Vector2i( 0, 0); break; // NPC is not moving
		case 1: direction = sf::Vector2i(-1, 0); break; // NPC is moving left
		case 2: direction = sf::Vector2i( 1, 0); break; // NPC is moving right
		case 3: direction = sf::Vector2i(0, -1); break; // NPC is moving up
		case 4: direction = sf::Vector2i( 0, 1); break; // NPC is moving down
		case 5: direction = sf::Vector2i(-1,-1); break; // NPC is moving left up
		case 6: direction = sf::Vector2i(1, -1); break; // NPC is moving right up
		case 7: direction = sf::Vector2i(-1, 1); break; // NPC is moving left down
		case 8: direction = sf::Vector2i( 1, 1); break; // NPC is moving right down
	}
	setDirection(direction);
}

void Character::onCollision(const theseus::engine::components::Solide&)
{
	if (idleActive)
		changeDirection();
}

void Character::startIdle()
{
	idleActive = true;
}

void Character::stopIdle()
{
	idleActive = false;
}

Character::~Character()
{}

