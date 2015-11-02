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

const float SPEED = 100.;
const float SPEED_DIAGONAL = 70.71; 	// SPEED / sqrt(2)
const int PLAYER_W = 32;
const int PLAYER_H = 50;

Character::Character()
{
	// animation
	setFrameSize(sf::Vector2i(PLAYER_W, PLAYER_H));
	setNumberOfFrames(4);
	setFrameRate(7);

	// walking
	setDirection(sf::Vector2i(0,0), true);

	this->setCollisionAreaTopLeft(sf::Vector2f(0, 40));
	this->setCollisionAreaBottomRight(sf::Vector2f(20, 50));
}


void Character::setDirection(sf::Vector2i d, bool force_update)
{
	// making changes to the animation will reset it to continue at the first frame.
	// this is why we must only update it when the direction really has changed.
	// Otherwise the animation would be resetted to the first frame on every update,
	// which would make it quite boring.
	if (d == direction && !force_update)
		return;

	direction = d;

	if (d == sf::Vector2i(0, 0))
	{
		setSpeed(sf::Vector2f(0, 0));
	}
	else if (d == sf::Vector2i(0, 1))
	{
		setSpeed(sf::Vector2f(0, SPEED));
		setFirstFramePosition(sf::Vector2i(0, 0));
	}
	else if (d == sf::Vector2i(0, -1))
	{
		setSpeed(sf::Vector2f(0, -SPEED));
		setFirstFramePosition(sf::Vector2i(0, 3 * PLAYER_H));
	}
	else if (d == sf::Vector2i(1, 0))
	{
		setSpeed(sf::Vector2f(SPEED, 0));
		setFirstFramePosition(sf::Vector2i(0, 2 * PLAYER_H));
	}
	else if (d == sf::Vector2i(1, 1))
	{
		setSpeed(sf::Vector2f(SPEED_DIAGONAL, SPEED_DIAGONAL));
		setFirstFramePosition(sf::Vector2i(0, 4 * PLAYER_H));
	}
	else if (d == sf::Vector2i(1, -1))
	{
		setSpeed(sf::Vector2f(SPEED_DIAGONAL, -SPEED_DIAGONAL));
		setFirstFramePosition(sf::Vector2i(0, 6 * PLAYER_H));
	}
	else if (d == sf::Vector2i(-1, 0))
	{
		setSpeed(sf::Vector2f(-SPEED, 0));
		setFirstFramePosition(sf::Vector2i(0, PLAYER_H));
	}
	else if (d == sf::Vector2i(-1, 1))
	{
		setSpeed(sf::Vector2f(-SPEED_DIAGONAL, SPEED_DIAGONAL));
		setFirstFramePosition(sf::Vector2i(0, 5 * PLAYER_H));
	}
	else if (d == sf::Vector2i(-1, -1))
	{
		setSpeed(sf::Vector2f(-SPEED_DIAGONAL, -SPEED_DIAGONAL));
		setFirstFramePosition(sf::Vector2i(0, 7 * PLAYER_H));
	}

	if (d == sf::Vector2i(0,0))
	{
		seek(0);
		pause();
	}
	else
	{
		start();
	}
}

Character::~Character()
{}

