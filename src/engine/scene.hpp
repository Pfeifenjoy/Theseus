#ifndef _ENGINE_SCENE_H
#define _ENGINE_SCENE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
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
		class KeyboardInput;
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

		// All game objects registered for keyboard events
		std::vector<components::KeyboardInput *> keyboardInput;
		
		// TODO: Replace some vectors with quad-trees as soon as it is implemented.

	public:
		//---- Constructors / Destructor ----------------------------------------------------------------
		
		/**
		 * Destructor
		 */
		virtual ~Scene();

		//---- Methods ----------------------------------------------------------------------------------
		
		/**
		 * Adds a game object to the scene
		 */
		void addGameObject(std::unique_ptr<GameObject> gameObject);

		/**
		 * Removed a game object from the scene
		 */
		std::unique_ptr<GameObject> removeGameObject(GameObject* gameObject);

		/**
		 * Draws the scene to the screen
		 */
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		//---- Methods: Register components -------------------------------------------------------------

		/**
		 * Adds a graphic that will be displayed during the drawing phase.
		 */
		void registerDrawable(int layer, const components::Drawable* drawable);
		void unregisterDrawable(const components::Drawable* drawable);

		/**
		 * Registers a game object to be updated in each frame. 
		 */
		void registerUpdate(components::Update *);
		void unregisterUpdate(components::Update *);

		/**
		 * Registers a game object to receive keyboard events.
		 */
		void registerKeyboardInput(components::KeyboardInput *);
		void unregisterKeyboardInput(components::KeyboardInput *);

		//---- Methods: Handle Events -------------------------------------------------------------------
		
		/**
		 * Passes the update event to the game objects.
		 */
		void handleUpdateEvent(float timePassed);

		/**
		 * Passes the key-down event to the game objects.
		 */
		void handleKeyDownEvent(sf::Keyboard::Key key);
	};
}
}

#endif
