/**
* @author Leon Mutschke
*/
#ifndef _THESEUS_GAME_SCENES_CHARACTERSELECTION_H
#define _THESEUS_GAME_SCENES_CHARACTERSELECTION_H

#include "../engine/scene.hpp"
#include "../engine/game.hpp"
#include "../gameobjects/textfield.hpp"
#include <memory>
#include <vector>
#include <utility>
#include <string>

namespace theseus
{
	namespace scenes
	{

		class CharacterSelection
			: public theseus::engine::Scene

		{
		private:
			short selectedItemIndex;
			std::vector<theseus::gameobjects::Textfield *> buttons;
			int screenWidth;
			int screenHeigth;
			sf::Keyboard::Key lastKeyEvent;

		public:
			//---- Constructor --------------------------------------------------------------------------------------
			// Generates a new menu scene
			CharacterSelection(const std::vector<std::string>& menuItem, theseus::engine::Game *game);

			//---- Destructor ---------------------------------------------------------------------------------------

			~CharacterSelection();


			//---- Methods ------------------------------------------------------------------------------------------

			/**
			* Passes the key-down event to the game objects.
			*/
			void handleKeyDownEvent(sf::Keyboard::Key key);

			void updateSelection();
			void setSelectedItemIndex(short);
			short getSelectedItemIndex();
			sf::Keyboard::Key getLastKeyEvent();


		};

	}
}
#endif
