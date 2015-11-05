#ifndef _THESEUS_ENGINE_COMPONENTS_DRAWABLE_H
#define _THESEUS_ENGINE_COMPONENTS_DRAWABLE_H

#include "position.hpp"
#include "base.hpp"
#include "../publisher.hpp"
#include <SFML/Graphics.hpp>
#include <array>

namespace theseus
{
namespace engine
{
class Scene;
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

		/**
		 * Registers the component at the given scene.
		 */
		void onRegisterComponents(Scene& scene);

		/**
		 * Unregisters the component at the given scene.
		 */
		void onUnregisterComponents(Scene& scene);

		/**
		 * Updates the registration of the component at the scene.
		 */
		void onUpdateRegistration(Scene& scene);

		/**
		 * the position at which the drawable is saved in the scene
		 * this can vary from the actual position of the game object.
		 */
		sf::Vector2f positionInSync;


	protected:

		/**
		 * Constructor
		 */
		Drawable();

		/**
		 * Registers a graphic to be drawn on a specific layer.
		 *
		 * Only layerts that were activated before the 
		 * "registerComponents"-Event is raised, will be drawn.
		 *
		 * So, if you want to use a certain layer, you should
		 * already activate it in your constructor.
		 * 
		 * Switching drawables by calling this method repeatedly,
		 * is perfectly supported at every time.
		 */
		void activateLayer(int layer, const sf::Drawable* drawable);

	public:

		/**
		 * Draws the content of the given layer to the render target.
		 */
		void draw(int layer, sf::RenderTarget& target, sf::RenderStates states) const;

		~Drawable();
	};

}
}
}

#endif
