#ifndef _THESEUS_ENGINE_COMPONENTS_MESSAGE_RECEIVER_H
#define _THESEUS_ENGINE_COMPONENTS_MESSAGE_RECEIVER_H 

#include "../publisher.hpp"
#include "../message.hpp"
#include "base.hpp"
#include "position.hpp"
#include <SFML/System.hpp>
#include "../scene.hpp"

namespace theseus
{
namespace engine
{

class GeneralEnvelope;

template <class T>
class Envelope;

namespace components
{

class GeneralMessageReceiver : public virtual Base
			     , public virtual Position
{
};

template <class T>
class MessageReceiver : GeneralMessageReceiver
{
	private:
		sf::Vector2f positionInSync;

		void onRegisterComponents(Scene& scene)
		{
			scene.registerMessageReceiver(this);
			positionInSync = getPosition();
		}

		void onRegistrationUpdate(Scene& scene)
		{
			scene.reRegisterMessageReceiver(positionInSync, this);
		}

		void onUnRegisterComponents(Scene& scene)
		{
			scene.unRegisterMessageReceiver(positionInSync, this);
		}

	protected:
		
		Publisher<const T&> evOnMessageReceived;

	public:
		void processMessage(const GeneralEnvelope& )
		{ /* do nothing - this is the wrong message type */ }

		void processMessage(const Envelope<T>& message)
		{
			// ok, process this!
			onMessageReceived(message.getMessage());
		}
};

}
}
}

#endif
