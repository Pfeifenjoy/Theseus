/**
* @author Philipp Pütz
*/
#ifndef _THESEUS_GAME_OBJECTS_MENU_H
#define _THESEUS_GAME_OBJECTS_MENU_H

#include "../engine/scene.hpp"
#include "../engine/game.hpp"
#include "../gameobjects/textfield.hpp"
#include <memory>
#include <vector>

namespace theseus
{
	namespace engine
	{

		class Menu
			: public engine::Scene
		
		{
		private:
			int selectedItemIndex;
			int numberOfItems;
			std::vector<gameobjects::Textfield *>  buttons;
			std::vector<std::unique_ptr<Scene> > scenes;
			engine::Game * game;

		public:
			//---- Constructor --------------------------------------------------------------------------------------
			// Generates a new menu scene, Menu(window.width, window.height, menuitems, scenes, current game)
			Menu(float width, float height, const std::vector<std::string>& menuItems, std::vector<std::unique_ptr<engine::Scene> >& scenes, engine::Game * game);

			//---- Destructor ---------------------------------------------------------------------------------------

			~Menu();


			//---- Methods ------------------------------------------------------------------------------------------

			/**
			* Passes the key-down event to the game objects.
			*/
			void handleKeyDownEvent(sf::Keyboard::Key key);
		};

	}
}
#endif
