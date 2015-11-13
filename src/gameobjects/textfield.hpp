/**
* @author Philipp Pütz, Arwed Mett
*/
#ifndef _THESEUS_GAME_OBJECTS_TEXTFIELD_H
#define _THESEUS_GAME_OBJECTS_TEXTFIELD_H

#include "../engine/gameobject.hpp"
#include "../engine/components/text.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class Textfield
			: public engine::GameObject
			, public virtual engine::components::Text
		{
		private:

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Textfield(std::string text, sf::Color textcolor);

			//---- Destructor ---------------------------------------------------------------------------------------

			~Textfield();

			// Returns the width of the textfield
			using Text::getTextWidth;
			int getTextWidth();

			// Sets the character size of the string in px
			using Text::setCharSize;
			void setCharSize(int size);

		};
	}
}

#endif
