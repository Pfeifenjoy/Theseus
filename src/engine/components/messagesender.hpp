#ifndef _THESEUS_ENGINE_COMPONENTS_MESSAGE_SENDER_H
#define _THESEUS_ENGINE_COMPONENTS_MESSAGE_SENDER_H 

#include <vector>
#include "../message.hpp"
#include "../envelope.hpp"
#include "position.hpp"
#include <SFML/System.hpp>

namespace theseus
{
namespace engine
{
namespace components
{

template <class T>
class MessageSender : public virtual Position 
{
	private:
		std::vector<Envelope<T> > outbox;

	protected:

		void sendMessage(const T& message, sf::Vector2f destination_tl, sf::Vector2f destination_br) 
		{
			Envelope<T> envelope(message, destination_tl, destination_br);
			outbox.push_back(envelope);
		}

		void sendMessage(const T& message, float maxDistanceX, float maxDistanceY)
		{
			auto position = getPosition();
			auto destination_tl = sf::Vector2f( position.x - maxDistanceX, position.y - maxDistanceY);
			auto destination_br = sf::Vector2f( position.x + maxDistanceX, position.y - maxDistanceY);
			sendMessage(message, destination_tl, destination_br);
		}
};

}
}
}
#endif
