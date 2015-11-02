/**
* @author Philipp P�tz
*/
#ifndef _THESEUS_GAME_OBJECTS_MENU_H
#define _THESEUS_GAME_OBJECTS_MENU_H

#include "../engine/scene.hpp"
#include "../gameobjects/button.hpp"

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
			Button button[];

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Menu(float width, float height, std::string * menuItems, int numberOfItems);

			//---- Destructor ---------------------------------------------------------------------------------------

			~Menu();


			//---- Methods ------------------------------------------------------------------------------------------

		};

	}
}
#endif
