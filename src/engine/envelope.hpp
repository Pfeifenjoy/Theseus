#ifndef _THESEUS_ENGINE_ENVELOPE_H
#define _THESEUS_ENGINE_ENVELOPE_H 

#include "message.hpp"
#include <SFML/System.hpp>

namespace theseus
{
namespace engine
{

class GeneralEnvelope 
{
	private:
		sf::Vector2f deliverToTopLeft;
		sf::Vector2f deliverToBottomRight;

	public:
		GeneralEnvelope(sf::Vector2f tl, sf::Vector2f br)
		{
			deliverToTopLeft = tl;
			deliverToBottomRight = br;
		}

		virtual ~GeneralEnvelope(){};

		virtual const Message& getMessage() const = 0;

		sf::Vector2f getDestinationTopLeft() const
		{
			return deliverToTopLeft;
		}

		sf::Vector2f getDestinationBottomRight() const
		{
			return deliverToBottomRight;
		}
};

template <class T>
class Envelope : GeneralEnvelope
{
	static_assert(std::is_base_of<Message, T>::value, "The message type must be derived from theseus::engine::message.");	
	private:
		T message;
		
	public:
		Envelope(const T& message, sf::Vector2f deliverTo_tl, sf::Vector2f deliverTo_br) : GeneralEnvelope(deliverTo_tl, deliverTo_br)
		{
			this->message = message;
		}

		const T& getMessage() const
		{
			return message;
		};
};

}
}

#endif
