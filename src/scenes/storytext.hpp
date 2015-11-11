/**
* @author Philipp Pütz, Arwed Mett, Dominic Steinhauser
*/
#ifndef _THESEUS_SCENES_STORYTEXT_H
#define _THESEUS_SCENES_STORYTEXT_H

#include "../engine/scene.hpp"
#include "../gameobjects/textfield.hpp"
#include <string>

namespace theseus
{
	namespace scenes
	{

		class StoryText
			: public engine::Scene

		{
		private:
			int screenWidth;
			int screenHeigth;

		public:
			//---- Constructor --------------------------------------------------------------------------------------
			// Generates a new Intro scene
			StoryText(int screenWidth, int screenHeigth, std::string storyText);

			//---- Destructor ---------------------------------------------------------------------------------------

			~StoryText();


			//---- Methods ------------------------------------------------------------------------------------------

			/**
			* Passes the key-down event to the game objects.
			*/
			void handleKeyDownEvent(sf::Keyboard::Key key);

		};

	}
}
#endif
