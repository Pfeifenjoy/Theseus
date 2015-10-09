#ifndef _THESEUS_ENGINE_COMPONENTS_SPRITE_H
#define _THESEUS_ENGINE_COMPONENTS_SPRITE_H

#include "position.hpp"
#include "drawable.hpp"
#include <SFML/Graphics.hpp>

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
		// The draw method needs to synchronize the 
		// position of the sprite with the position of the 
		// GameObject. Even if this changes the physical state of the 
		// object in memory, it does not change the logical
		// state of the object. So, const-correctness is still met.
		// However, to do this, the sprite has to be mutable!
		mutable sf::Sprite mysprite;

	protected:

		/**
		 * Draws the GameObject to the screen.
		 */
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	public:

		/**
		 * Sets the texture of the Sprite.
		 *
		 * Note that this method is just a shortcut.
		 * It can also be done via sprite().setTexture().
		 * All other tweaks that need to be done to the sprite
		 * will have to be done this way, too.
		 */
		void setTexture(const sf::Texture&);

		/**
		 * Returns a reference(!) to the sprite.
		 */
		sf::Sprite& sprite();

	};
}
}
}
#endif
