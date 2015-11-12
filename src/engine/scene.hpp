/**
 * @author Tobias Dorra, Arwed Mett
 */
#ifndef _ENGINE_SCENE_H
#define _ENGINE_SCENE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <memory>
#include <array>
#include <unordered_set>
#include "grid.hpp"
#include <typeinfo>
#include <unordered_map>

namespace theseus
{
namespace engine
{
	class GameObject;
	class GeneralEnvelope;

	namespace components
	{
		class Base;
		class Drawable;
		class Update;
		class KeyboardInput;
		class Solide;
		class CollisionDetector;
		class Camera;
		template<class T>
		class MessageReceiver;
		class GeneralMessageReceiver;
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
		std::array<Grid<const components::Drawable *, 100, 100, 64> , 5> drawables;

		// All game objects that need to be updated in each frame.
		std::vector<components::Update *> update;

		// All game objects registered for keyboard events
		std::vector<components::KeyboardInput *> keyboardInput;

		// All game objects that are involved in colision detection (Solide component)
		Grid<components::Solide *, 100, 100, 64> solide;

		// The active camera
		const components::Camera* activeCamera = nullptr;

		// All game objects that can receive messages
		std::unordered_map<size_t, Grid<components::GeneralMessageReceiver *, 100, 100, 64> > messageReceiver;		

	protected:
		bool finished=false;

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

		/**
		 * Messaging system
		 */
		template <class T_Message>
		void registerMessageReceiver(components::MessageReceiver<T_Message> *);
		template <class T_Message>
		void unRegisterMessageReceiver(sf::Vector2f position, components::MessageReceiver<T_Message> *);
		template <class T_Message>
		void reRegisterMessageReceiver(sf::Vector2f oldPosition, components::MessageReceiver<T_Message> *);
		template <class T_Message>
		void deliverMessage(const T_Message& message, sf::Vector2f tl, sf::Vector2f br);

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

		/**
		 * Check if the scene is finished.
		 */
		bool checkFinished();
	};
}
}

//---- Implementation of the template methods -----------------------------------------------------------------------------------------------------------

#include "components/messagereceiver.hpp"

template <class T_Message>
void theseus::engine::Scene::registerMessageReceiver(theseus::engine::components::MessageReceiver<T_Message> * receiver)
{
	messageReceiver[typeid(T_Message).hash_code()].insert(receiver->getPosition(), receiver);	
}

template <class T_Message>
void theseus::engine::Scene::unRegisterMessageReceiver(sf::Vector2f position, theseus::engine::components::MessageReceiver<T_Message> * receiver)
{
	messageReceiver[typeid(T_Message).hash_code()].remove(position, receiver);
}

template <class T_Message>
void theseus::engine::Scene::reRegisterMessageReceiver(sf::Vector2f position, theseus::engine::components::MessageReceiver<T_Message> * receiver)
{
	messageReceiver[typeid(T_Message).hash_code()].updatePosition(position, receiver->getPosition(), receiver);
}

template <class T_Message>
void theseus::engine::Scene::deliverMessage(const T_Message& message, sf::Vector2f tl, sf::Vector2f br)
{
	auto receivers = messageReceiver[typeid(T_Message).hash_code()].find(tl, br);
	for (auto receiver : receivers)
	{
		sf::Vector2f position = receiver.second->getPosition();
		if (position.x > tl.x && position.y > tl.y && position.x < br.x && position.y < br.y)
		{
			needsRegistrationUpdate.insert(receiver.second);
			dynamic_cast<theseus::engine::components::MessageReceiver<T_Message>*>(receiver.second)->processMessage(message);
		}
	}
}

#endif
