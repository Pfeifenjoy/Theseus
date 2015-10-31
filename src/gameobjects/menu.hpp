/*
* Philipp Pütz
*/
#ifndef _THESEUS_GAME_OBJECTS_MENU_H
#define _THESEUS_GAME_OBJECTS_MENU_H

#include "../engine/gameobject.hpp"

namespace theseus
{
	namespace engine
	{
		class Scene;
	}
	namespace gameobjects
	{
		class Menu
			: public engine::GameObject
			, public virtual engine::Scene
		{
		private:
			int selectedItemIndex;
			int numberOfItems;
			sf::Font font;
			sf::Text * menu;

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Menu(float width, float height, std::string * menuItems, int numberOfItems);

			//---- Destructor ---------------------------------------------------------------------------------------

			~Menu();


			//---- Methods ------------------------------------------------------------------------------------------
			void draw(sf::RenderWindow &window);
			void MoveUp();
			void MoveDown();
			int GetPressedItem() { return selectedItemIndex; }

		};
	}
}
#endif
