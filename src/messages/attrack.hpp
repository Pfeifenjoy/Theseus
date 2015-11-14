#ifndef _THESEUS_MESSAGES_ATTRACK
#define _THESEUS_MESSAGES_ATTRACK 

#include <SFML/System.hpp>

namespace theseus
{

namespace messages 
{

struct Attrack
{
	int priority;
	sf::Vector2f position;
};

}
}

#endif
