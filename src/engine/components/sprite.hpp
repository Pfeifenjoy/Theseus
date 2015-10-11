#ifndef _THESEUS_ENGINE_COMPONENTS_SPRITE_H
#define _THESEUS_ENGINE_COMPONENTS_SPRITE_H

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

	class Sprite : public virtual Position, public virtual Drawable
	{
	private:
	
		// The Sprite to draw
		std::array<sf::Sprite, 5> sprites;

	public:

		/**
		 * Sets the texture of the Sprite.
		 *
		 * Note that this method is just a shortcut.
		 * It can also be done via sprite().setTexture().
		 * All other tweaks that need to be done to the sprite
		 * will have to be done this way, too.
		 */
		void setTexture(int layer, const sf::Texture&);

		/**
		 * Returns a reference(!) to the sprite.
		 */
		sf::Sprite& sprite(int layer);

	};
}
}
}
#endif
