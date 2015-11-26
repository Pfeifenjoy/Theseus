/**
* @author Philipp Pütz, Arwed Mett
*/
#ifndef _THESEUS_GAME_OBJECTS_MENU_H
#define _THESEUS_GAME_OBJECTS_MENU_H

#include "../engine/scene.hpp"
#include "../gameobjects/textfield.hpp"
#include <memory>
#include <vector>
#include <utility>
#include <string>

namespace theseus
{
	namespace scenes
	{

		class Menu
			: public theseus::engine::Scene

		{
		private:
			short selectedItemIndex;
			std::vector<theseus::gameobjects::Textfield *> buttons;

			int screenWidth;
			int screenHeigth;

		public:
			//---- Constructor --------------------------------------------------------------------------------------
			// Generates a new menu scene
			Menu(const std::vector<std::string>& menuItem, int screenWidth, int screenHeigth);

			//---- Destructor ---------------------------------------------------------------------------------------

			~Menu();


			//---- Methods ------------------------------------------------------------------------------------------

			/**
			* Passes the key-down event to the game objects.
			*/
			void handleKeyDownEvent(sf::Keyboard::Key key);

			// Changes the color of the selected button
			void updateSelection();

			// Sets preselected button
			void setSelectedItemIndex(short);

			// Returns the acutal selected button
			short getSelectedItemIndex();
		};
	}
}
#endif
