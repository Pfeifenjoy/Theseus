/**
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_HIGHSCORE_H
#define _THESEUS_GAME_HIGHSCORE_H

#include "../engine/scene.hpp"
#include "../gameobjects/textfield.hpp"
#include <memory>
#include <vector>
#include <string>

namespace theseus
{
	namespace scenes
	{

		class Highscore
			: public engine::Scene

		{
		private:
			int screenWidth;
			int screenHeigth;
			gameobjects::Textfield * textfield;
			std::string getHighscore(float timeLeft);

		public:
			//---- Constructor --------------------------------------------------------------------------------------
			// Generates a new Intro scene
			Highscore(int screenWidth, int screenHeigth, float time);

			//---- Destructor ---------------------------------------------------------------------------------------

			~Highscore();


			//---- Methods ------------------------------------------------------------------------------------------

			/**
			* Passes the key-down event to the game objects.
			*/
			void handleKeyDownEvent(sf::Keyboard::Key key);

		};

	}
}
#endif
