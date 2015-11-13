#ifndef _THESEUS_ENGINE_COMPONENTS_MESSAGE_RECEIVER_H
#define _THESEUS_ENGINE_COMPONENTS_MESSAGE_RECEIVER_H 

#include "../publisher.hpp"
#include "base.hpp"
#include "position.hpp"
#include <SFML/System.hpp>
#include <functional>

namespace theseus
{
namespace engine
{

namespace components
{

class GeneralMessageReceiver : public virtual Base, public virtual Position
{};

/**
 * The MessageReceiver-component provides an event that
 * is triggered when a message arrives at the game object.
 *
 * The receiver will only handle events of a single type.
 * This type needs to be given to the receiver as a template parameter.
 */
template <class T>
class MessageReceiver : public GeneralMessageReceiver
{
	private:
		/**
		 * The position at which the component is registered 
		 * at the scene.
		 */
		sf::Vector2f positionInSync;

		/**
		 * Registration-Lifetime events from the scene
		 */
		void onRegisterComponents(Scene& scene);
		void onRegistrationUpdate(Scene& scene);
		void onUnRegisterComponents(Scene& scene);

	protected:
		
		/**
		 * The evOnMessageReceived-Event is triggered, when a mmessage arrives at the game object.
		 */
		Publisher<const T&> evOnMessageReceived;

	public:
		/**
		 * Called by the scene, when a message arrives
		 * The message will than be handed over to the evOnMessageReceived-Publisher.
		 */
		void processMessage(const T& message);

		/**
		 * Constructor
		 */
		MessageReceiver();
};

}
}
}

//---- implementation -----------------------------------------------------------------------------------------------------

#include "../scene.hpp"

template<class T>
void theseus::engine::components::MessageReceiver<T>::onRegisterComponents(Scene& scene)
{
	scene.registerMessageReceiver(this);
	positionInSync = getPosition();
}

template<class T>
void theseus::engine::components::MessageReceiver<T>::onRegistrationUpdate(Scene& scene)
{
	scene.reRegisterMessageReceiver(positionInSync, this);
	positionInSync = getPosition();
}

template<class T>
void theseus::engine::components::MessageReceiver<T>::onUnRegisterComponents(Scene& scene)
{
	scene.unRegisterMessageReceiver(positionInSync, this);
}

template<class T>
void theseus::engine::components::MessageReceiver<T>::processMessage(const T& message)
{
	// ok, process this!
	evOnMessageReceived(message);
}

template<class T>
theseus::engine::components::MessageReceiver<T>::MessageReceiver()
{
	evRegisterComponents.subscribe(std::bind(&MessageReceiver::onRegisterComponents, this, std::placeholders::_1));
	evUnregisterComponents.subscribe(std::bind(&MessageReceiver::onUnRegisterComponents, this, std::placeholders::_1));
	evUpdateComponentRegistrations.subscribe(std::bind(&MessageReceiver::onRegistrationUpdate, this, std::placeholders::_1));
}

#endif
