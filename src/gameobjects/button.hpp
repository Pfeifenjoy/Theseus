/**
* @author Philipp Pütz
*/
#ifndef _THESEUS_GAME_OBJECTS_BUTTON_H
#define _THESEUS_GAME_OBJECTS_BUTTON_H

#include "../engine/gameobject.hpp"
#include "../engine/components/text.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class Button
			: public engine::GameObject
			, public virtual engine::components::Text
		{
		private:
					
		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Button(std::string text, sf::Vector2f position, sf::Color textcolor);

			//---- Destructor ---------------------------------------------------------------------------------------

			~Button();
		};
	}
}

#endif
