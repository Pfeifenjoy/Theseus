/**
* @author Philipp Pütz
*/
#ifndef _THESEUS_ENGINE_COMPONENTS_TEXT_H
#define _THESEUS_ENGINE_COMPONENTS_TEXT_H

#include "position.hpp"
#include "drawable.hpp"
#include <SFML/Graphics.hpp>
#include <array>

namespace theseus
{
	namespace engine
	{
		namespace components
		{

			class Text : public virtual Position, public virtual Drawable
			{
			private:

				// The Sprite to draw
				std::array<sf::Text, 5> texts;
				sf::Font font;

			public:

				// Sets the texts to show
				void setText(int layer, std::string);

				// Sets the text color
				void setColor(int layer, sf::Color);

				// Sets the text size in px
				void setTextSize(int layer, int textSize);

				/**
				* Returns a reference(!) to the text.
				*/
				sf::Text& text(int layer);

			public:
				virtual ~Text();

			};
		}
	}
}
#endif
