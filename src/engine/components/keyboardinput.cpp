/**
 * Autor: Tobias Dorra
 */
#include "keyboardinput.hpp"
#include "../scene.hpp"
#include <functional>

using namespace std;
using namespace std::placeholders;
using namespace theseus::engine;
using namespace theseus::engine::components;

KeyboardInput::KeyboardInput()
{
	evRegisterComponents.subscribe(bind(&KeyboardInput::onRegisterComponents, this, _1));
	evUnregisterComponents.subscribe(bind(&KeyboardInput::onUnregisterComponents, this, _1));
}

KeyboardInput::~KeyboardInput()
{}

void KeyboardInput::onRegisterComponents(Scene& scene)
{
	scene.registerKeyboardInput(this);
}

void KeyboardInput::onUnregisterComponents(Scene& scene)
{
	scene.unregisterKeyboardInput(this);
}

void KeyboardInput::handleKeyDown(sf::Keyboard::Key key)
{
	evKeyDown(key);	
}
