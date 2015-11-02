#ifndef _THESEUS_ENGINE_COMPONENTS_SOLIDE_H
#define _THESEUS_ENGINE_COMPONENTS_SOLIDE_H 

#include "base.hpp"
#include "position.hpp"
#include <SFML/System.hpp>

namespace theseus
{
namespace engine
{

class Scene;

namespace components
{

class Solide : public virtual Base
	     , public virtual Position
{
private:

	// collision rectangle
	sf::Vector2f collisionAreaTL;
	sf::Vector2f collisionAreaBR;

	// event callbacks
	void onRegisterComponents(Scene& scene);
	void onUnregisterComponents(Scene& scene);
	void onUpdateRegistration(Scene& scene);

	// position synchronisation
	sf::Vector2f positionInSync;

public:

	//---- Constructors / Deconstructors -----------------------------------------------------------------------------------

	/**
	 * Constructor
	 */
	Solide();

	/**
	 * Virtual destructor
	 */
	virtual ~Solide();

	//---- Getters / Setters ----------------------------------------------------------------------------------------------
	
	/**
	 * The left top corner of the collision area.
	 * This is given relative to the position of the game object.
	 */
	sf::Vector2f getCollisionAreaTopLeft() const;
	void setCollisionAreaTopLeft(sf::Vector2f);

	/**
	 * The bottom right corner of the collision area.
	 * This is given relative to the position of the game object.
	 */
	sf::Vector2f getCollisionAreaBottomRight() const;
	void setCollisionAreaBottomRight(sf::Vector2f);

	/**
	 * The collision Area in absolute values
	 */
	sf::Vector2f getAbsoluteCollisionAreaTopLeft() const;
	sf::Vector2f getAbsoluteCollisionAreaBottomRight() const;

};

}
}
}

#endif
