#ifndef _ENGINE_SCENE_H
#define _ENGINE_SCENE_H

#include "quadtree.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <memory>
#include <array>
#include <unordered_set>

namespace theseus
{
namespace engine
{
	class GameObject;

	namespace components
	{
		class Base;
		class Drawable;
		class Update;
		class KeyboardInput;
		class Solide;
		class CollisionDetector;
		class Camera;
	}

	class Scene : public sf::Drawable
	{
	private:
		// All game objects of this scene
		std::vector<std::unique_ptr<GameObject> > gameObjects;
			
		// All game object on which updateRegistration potentially needs to be called.
		std::unordered_set<components::Base *> needsRegistrationUpdate;
		std::unordered_set<components::Base *> needsRegistrationUpdate_previous;
		
		// All drawable objects, grouped by layer
		std::array<QuadTree<const components::Drawable *> , 5> drawables;

		// All game objects that need to be updated in each frame.
		std::vector<components::Update *> update;

		// All game objects registered for keyboard events
		std::vector<components::KeyboardInput *> keyboardInput;

		// All game objects that are involved in colision detection (Solide component)
		QuadTree<components::Solide *> solide;

		// The active camera
		const components::Camera* activeCamera = nullptr;

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
		 * Sets the active camera
		 */
		void setCamera(const components::Camera * camera);

		/**
		 * Draws the scene to the screen
		 */
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		//---- Methods: Register components -------------------------------------------------------------

		/**
		 * Adds a graphic that will be displayed during the drawing phase.
		 */
		void registerDrawable(int layer, const components::Drawable* drawable);
		void reRegisterDrawable(int layer, sf::Vector2f oldPosition, const components::Drawable*);
		void unregisterDrawable(int layer, sf::Vector2f position, const components::Drawable* drawable);

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

		/**
		 * Registers a game object that should be used for collision detection.
		 */
		void registerSolide(components::Solide *);
		void unRegisterSolide(sf::Vector2f position, components::Solide *);
		void reRegisterSolide(sf::Vector2f oldPosition, components::Solide *); 	// should be called after the location of the GO has changed
		void checkCollisions(components::CollisionDetector * component);

		//---- Methods: Handle Events -------------------------------------------------------------------
		
		/**
		 * This event gets called after the scene has been started.
		 */
		void handleSceneStartedEvent();
		
		/**
		 * Passes the update event to the game objects.
		 */
		void handleUpdateEvent(float timePassed);

		/**
		 * Passes the key-down event to the game objects.
		 */
		virtual void handleKeyDownEvent(sf::Keyboard::Key key);
	};
}
}

#endif
