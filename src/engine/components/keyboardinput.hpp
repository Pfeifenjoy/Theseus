#ifndef _THESEUS_ENGINE_COMPONENTS_KEYBOARD_INPUT_H
#define _THESEUS_ENGINE_COMPONENTS_KEYBOARD_INPUT_H 

#include "../publisher.hpp"
#include "base.hpp"
#include <SFML/Window.hpp>

namespace theseus
{
namespace engine
{

class Scene;

namespace components
{

class KeyboardInput : public virtual Base
{
private:

	/**
	 * This is the place to register the component at the scene.
	 */
	void onRegisterComponents(Scene&);
	void onUnregisterComponents(Scene&);

protected:
	
	/**
	 * This event will be triggered when a key is pressed.
	 */
	Publisher<sf::Keyboard::Key> evKeyDown;

public:
	/**
	 * Constructor
	 */
	KeyboardInput();

	/**
	 * Virtual destructor
	 */
	virtual ~KeyboardInput();

	/**
	 * Called from the scene when the key was pressed
	 */
	void handleKeyDown(sf::Keyboard::Key key);

};

}
}
}

#endif
