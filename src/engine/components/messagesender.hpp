#ifndef _THESEUS_ENGINE_COMPONENTS_MESSAGE_SENDER_H
#define _THESEUS_ENGINE_COMPONENTS_MESSAGE_SENDER_H 

#include "position.hpp"
#include "base.hpp"
#include <functional>
#include <SFML/System.hpp>
#include <vector>

namespace theseus
{
namespace engine
{
namespace components
{

/**
 * The messageSender component provides the methods to send messages to other game objects.
 *
 * The message itself can be an value of an arbitrary type.
 * The type that is used for the message should be given to the MessageSender as a template parameter.
 */
template <class T>
class MessageSender : public virtual Position 
		    , public virtual Base
{
	private:

		//Struct to store a message together with its destination
		struct Envelope
		{
			sf::Vector2f destination_tl;
			sf::Vector2f destination_br;
			T message;
		};

		// All messages that have to be sent.
		std::vector<Envelope> outbox;

		/**
		 * Delivers the messages from the outbox to the scene.
		 */
		void onReRegisterComponent(Scene& scene);

	protected:

		/**
		 * Constructor
		 */
		MessageSender();

		/**
		 * Sends a message.
		 * The message will be delivered to all game objects that
		 * 	- can receive the message type
		 * 	- are inside the rect defined by the tl/br coordinates.
		 */
		void sendMessage(const T& message, sf::Vector2f destination_tl, sf::Vector2f destination_br);

		/**
		 * Sends a message.
		 * This overload of sendMessage behaves like the above one, however the rect that
		 * defines where the message is delivered to, is
		 * 	- centered at the position of the sending game object
		 * 	- has a width of 2*maxDistanceX
		 * 	- has a height of 2*maxDistanceY
		 */
		void sendMessage(const T& message, float maxDistanceX, float maxDistanceY);
};

}
}
}

//---- implementation -----------------------------------------------------------------------------------------------------------------------

#include "../scene.hpp"

template <class T>
theseus::engine::components::MessageSender<T>::MessageSender()
{
	evUpdateComponentRegistrations.subscribe(std::bind(&MessageSender<T>::onReRegisterComponent, this, std::placeholders::_1));
}

template <class T>
void theseus::engine::components::MessageSender<T>::sendMessage(const T& message, sf::Vector2f destination_tl, sf::Vector2f destination_br) 
{
	Envelope envelope;
	envelope.destination_tl = destination_tl;
	envelope.destination_br = destination_br;
	envelope.message = message;
	outbox.push_back(envelope);
}

template<class T>
void theseus::engine::components::MessageSender<T>::sendMessage(const T& message, float maxDistanceX, float maxDistanceY)
{
	auto position = getPosition();
	auto destination_tl = sf::Vector2f( position.x - maxDistanceX, position.y - maxDistanceY);
	auto destination_br = sf::Vector2f( position.x + maxDistanceX, position.y + maxDistanceY);
	sendMessage(message, destination_tl, destination_br);
}

template <class T>
void theseus::engine::components::MessageSender<T>::onReRegisterComponent(Scene& scene)
{
	for (auto envelope : outbox)
	{
		scene.deliverMessage(envelope.message, envelope.destination_tl, envelope.destination_br);
	}
	outbox.clear();
}

#endif
