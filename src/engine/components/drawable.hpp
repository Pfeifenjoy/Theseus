#ifndef _THESEUS_ENGINE_COMPONENTS_DRAWABLE_H
#define _THESEUS_ENGINE_COMPONENTS_DRAWABLE_H

#include "position.hpp"
#include "base.hpp"
#include "../publisher.hpp"
#include "../subscription.hpp"
#include <SFML/Graphics.hpp>
#include <array>

namespace theseus
{
namespace engine
{
namespace components
{
	class Drawable 
		: public virtual Position
		, public virtual Base
	{
	private:
		/**
		 * The pointers to the actual drawable object for each layer
		 */
		std::array<const sf::Drawable*, 5> layers = {{nullptr, nullptr, nullptr, nullptr, nullptr}};

		Subscription<> baseInitialized;	

		void onBaseInitialized();
	public:

		/**
		 * Constructor
		 */
		Drawable();

		/**
		 * Registers a graphic to be drawn on a specific layer.
		 */
		void setDrawableOnLayer(int layer, const sf::Drawable* drawable);

		/**
		 * Draws the content of the given layer to the render target.
		 */
		void draw(int layer, sf::RenderTarget& target, sf::RenderStates states) const;
	};

}
}
}

#endif
