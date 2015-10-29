#include "animation.hpp"
#include <functional>

using namespace std;
using namespace std::placeholders;
using namespace theseus::engine::components;

Animation::Animation()
{
	evOnUpdate.subscribe(bind(&Animation::onUpdate, this, _1));
	animatedLayer = 3;
	firstFrame = sf::Vector2i(0,0);
	nrOfFrames = 1;
	timePerFrame = .2;
	repeat = true;
	timePassed = 0;
	frameNumber = 0;
	playing = false;
	displayFrame();
}

Animation::~Animation()
{}

void Animation::onUpdate(float t)
{
	if (!playing)
		return;

	timePassed += t;

	while (timePassed > timePerFrame)
	{
		timePassed -= timePerFrame;
		nextFrame();
	}
}

void Animation::nextFrame()
{
	++frameNumber;

	// if the end has been reached...
	if (frameNumber == nrOfFrames && repeat)
	{
		if (repeat)
		{
			frameNumber = 0;
		}
		else
		{
			--frameNumber;
			playing = false;
		}

	}

	// show it
	displayFrame();
}

void Animation::displayFrame()
{
	sf::Vector2i position;
	position.y = firstFrame.y + frameOffset.y * frameNumber;
	position.x = firstFrame.x + frameOffset.x * frameNumber;
	try {
		sprite(animatedLayer).setTextureRect(sf::IntRect(position, frameSize));
	} 
	catch (...) 
	{/* There is no texture on the given layer */}
}

void Animation::start()
{
	playing = true;
	timePassed = 0;
}

void Animation::pause()
{
	playing = false;
}

void Animation::seek(int frame)
{
	frameNumber = frame % nrOfFrames;
	timePassed = 0;
	displayFrame();
}

void Animation::setFrameSize(sf::Vector2i size)
{
	frameSize = size;
	frameOffset = sf::Vector2i(size.x, 0);
	displayFrame();
}

sf::Vector2i Animation::getFrameSize() const
{
	return frameSize;
}

void Animation::setFirstFramePosition(sf::Vector2i pos)
{
	firstFrame = pos;
	displayFrame();
}

sf::Vector2i Animation::getFirstFramePosition() const
{
	return firstFrame;
}

void Animation::setFramesOffset(sf::Vector2i offset)
{
	frameOffset = offset;
	displayFrame();
}

sf::Vector2i Animation::getFramesOffset() const
{
	return frameOffset;
}

void Animation::setNumberOfFrames(int nr)
{
	nrOfFrames = nr;
	frameNumber = 0;
	displayFrame();
}

int Animation::getNumberOfFrames() const
{
	return nrOfFrames;
}

void Animation::setFrameRate(float fps)
{
	timePerFrame = 1. / fps;
	timePassed = 0;
}

float Animation::getFrameRate() const
{
	return 1. / timePerFrame;
}

void Animation::setRepeating(bool repeat)
{
	this->repeat = repeat;	
}

bool Animation::isRepeating() const
{
	return repeat;
}

void Animation::setAnimatedLayer(int layer)
{
	animatedLayer = layer;
	displayFrame();
}

int Animation::getAnimatedLayer() const
{
	return animatedLayer;
}
