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

				// The font to use for the text.
				static sf::Font& font();
			public:

				// Sets the texts to show
				void setText(int layer, std::string);

				// Hides the text on the given layer.
				void unsetText(int layer);

				// Sets the text color
				void setColor(int layer, sf::Color);

				// Sets the text size in px
				virtual void setCharSize(int layer, int textSize);

				// Retuns the width of the text
				virtual int getTextWidth(int layer);

				// Retuns the style of the text (use sf::Text::Bold etc ...)
				virtual void setStyle(int layer, sf::Text::Style style);

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
