#ifndef _ENGINE_SCENE_H
#define _ENGINE_SCENE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <array>

namespace theseus
{
namespace engine
{
	class GameObject;

	namespace components
	{
		class Drawable;
		class Update;
	}

	class Scene : public sf::Drawable
	{
	private:
		// All game objects of this scene
		std::vector<std::unique_ptr<GameObject> > gameObjects;
			
		// All drawable objects, grouped by layer
		std::array<std::vector<const components::Drawable *> , 5> drawables;

		// All game objects that need to be updated in each frame.
		std::vector<components::Update *> update;
		
		// TODO: Replace some vectors with quad-trees as soon as it is implemented.

	public:
		//---- Constructors / Destructor ----------------------------------------------------------------
		
		/**
		 * Destructor
		 */
		virtual ~Scene();

		//---- Methods ----------------------------------------------------------------------------------
		
		void addGameObject(std::unique_ptr<GameObject> gameObject);

		//---- Methods: Register components -------------------------------------------------------------

		/**
		 * Adds a graphic that will be displayed during the drawing phase.
		 */
		void addDrawable(int layer, const components::Drawable* drawable);

		/**
		 * Registers a game object to be updated in each frame. 
		 */
		void addUpdate(components::Update *);

		/**
		 * Draws the scene to the screen
		 */
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		//---- Methods: Handle Events -------------------------------------------------------------------
		
		/**
		 * Passes the update event to each GameObject.
		 */
		void handleUpdateEvent(float timePassed);
	};
}
}

#endif
