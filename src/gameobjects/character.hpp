/**
 * @autor Arwed Mett
 */
#ifndef _THESEUS_GAME_OBJECTS_CHARACTER_H
#define _THESEUS_GAME_OBJECTS_CHARACTER_H

#include "../engine/gameobject.hpp"
#include "../engine/components/update.hpp"
#include "../engine/components/animation.hpp"
#include "../engine/components/speed.hpp"
#include "../engine/components/collisionresolver.hpp"
#include "../engine/components/positionable.hpp"
#include "../engine/components/text.hpp"
#include "../engine/components/messagesender.hpp"
#include "../messages/attrack.hpp"
#include <SFML/System.hpp>
#include <string>

namespace theseus
{
namespace gameobjects
{
	class Character
		//: public engine::GameObject
		: public theseus::engine::components::Positionable
		, public virtual engine::components::Animation
		, public virtual engine::components::Speed
		, public virtual engine::components::CollisionResolver
		, public virtual engine::components::Text
		, public virtual engine::components::Update
		, public virtual engine::components::MessageSender<messages::Attrack>
	{
	private:
		// state changes
		sf::Vector2i direction;

		// Speed Settings
		float speedMultiplier;

		// remaining time for the speech bubble
		float remainingSpeechBubbleTime = 0;

		// auto-speech ("as") settings (see startAutoSpeech() for descriptions)
		std::vector<std::string> as_sentences;
		float as_duration;
		float as_minPause;
		float as_pauseRandomLength;
		bool as_loop;
		bool as_shuffle;
		bool as_active = false;
		std::vector<std::string>::iterator as_position;
		float as_currentPause;

		//idle around
		bool idleActive = false;
		float directionTimeout = 2;
		void changeDirection();
		void onCollision(const engine::components::Solide&);

		// called on the update event.
		void onUpdate(float passedTime);

	public:
		void setDirection(sf::Vector2i direction, bool force_update = false);

		//---- Constructor --------------------------------------------------------------------------------------

		Character();

		//---- Destructor ---------------------------------------------------------------------------------------

		~Character();

		// Speed Multiplier setter
		void setSpeedMultiplier(float value);

		// Shows a speech bubble with some text.
		// The bubble is shown for <duration> seconds. Then it automatically vanishes.
		void say(std::string text, float duration = 3.);
		void interruptSay(); 	// hides the current speech bubble

		// Lets the character automatically talk some stuff
		//
		// sentences: which text to say. One entry in the array is one speech bubble.
		// duration: how long to show the speech bubbles.
		// minPause : the minimal delay between two speech bubbles
		// maxPause : the maximal delay between two speech bubbles.
		// 		the actual delay between two speech bubbles will be a random value between minPause and maxPause.
		// 		values are given in seconds. 
		// loop : whether to stop after the last sentence or to restart at the beginning
		// shuffle: whether to randomize the order of the sentences
		void startAutoSpeech(const std::vector<std::string>& sentences, float duration, float minPause, float maxPause, bool loop, bool shuffle);

		// Start and stop IDLEing
		void startIdle();
		void stopIdle();
	};
}
}

#endif
