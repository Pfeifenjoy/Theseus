/**
* @author Philipp Pütz
*/
#ifndef _THESEUS_GAME_INTRO_H
#define _THESEUS_GAME_INTRO_H

#include "../engine/scene.hpp"
#include "../gameobjects/textfield.hpp"
#include <memory>
#include <vector>

namespace theseus
{
	namespace scenes
	{

		class Intro
			: public engine::Scene

		{
		private:
			int screenWidth;
			int screenHeigth;
			gameobjects::Textfield * textfield;

		public:
			//---- Constructor --------------------------------------------------------------------------------------
			// Generates a new Intro scene
			Intro(int screenWidth, int screenHeigth);

			//---- Destructor ---------------------------------------------------------------------------------------

			~Intro();


			//---- Methods ------------------------------------------------------------------------------------------

			/**
			* Passes the key-down event to the game objects.
			*/
			void handleKeyDownEvent(sf::Keyboard::Key key);

		};

	}
}
#endif
