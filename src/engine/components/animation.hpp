/**
 * Autor: Tobias Dorra
 */
#ifndef _THESEUS_ENGINE_COMPONENTS_ANIMATION_H
#define _THESEUS_ENGINE_COMPONENTS_ANIMATION_H 

#include "sprite.hpp"
#include "update.hpp"
#include <SFML/System.hpp>

namespace theseus
{
namespace engine
{
namespace components
{

/**
 * This component helps playing animations by showing different parts of the gameObject's texture repeatedly.
 */
class Animation
	: public virtual Sprite
	, public virtual Update
{
private:
	// properties that describe the animation
	sf::Vector2i frameSize;
	sf::Vector2i firstFrame;
	sf::Vector2i frameOffset;
	int nrOfFrames;
	float timePerFrame;
	bool repeat;
	int animatedLayer;

	// current state of the animation
	float timePassed;
	int frameNumber;
	bool playing;

	/**
	 * This is the place where the magic happens
	 */
	void onUpdate(float passedTime);
	void nextFrame();
	void displayFrame();

protected:

	//---- methods to controll the animation -------------------------------------------------------------
	
	/**
	 * Starts the animation
	 *
	 * If the animation was paused before, it will continue to play at the paused position.
	 */
	void start();

	/**
	 * Pauses the animation
	 */
	void pause();

	/**
	 * Sets the current frame number
	 */
	void seek(int frameNumber);

	//---- getters / setters -----------------------------------------------------------------------------
	
	/**
	 * The dimensions of the rectangle that is displayed
	 */
	void setFrameSize(sf::Vector2i size);
	sf::Vector2i getFrameSize() const;

	/**
	 * The position of the top left corner of the first frame on the tilesheet texture.
	 */
	void setFirstFramePosition(sf::Vector2i pos);
	sf::Vector2i getFirstFramePosition() const;

	/**
	 * The space between two frames.
	 *
	 * Typically this is ( frameSize.x , 0 ).
	 */
	void setFramesOffset(sf::Vector2i offset);
	sf::Vector2i getFramesOffset() const;

	/**
	 * The number of frames the animation consists of.
	 */
	void setNumberOfFrames(int nr);
	int getNumberOfFrames() const;

	/**
	 * The number of frames that schould be displayed in one second.
	 */
	void setFrameRate(float fps);
	float getFrameRate() const;

	/**
	 * Does the animation continue with the first frame after the last frame was shown?
	 */
	void setRepeating(bool repeat);
	bool isRepeating() const;

	/**
	 * The layer the animation is performed on.
	 */
	void setAnimatedLayer(int layer);
	int getAnimatedLayer() const;
	

public:
	Animation();
	virtual ~Animation();
};

}
}
}

#endif
