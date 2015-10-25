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
}

KeyboardInput::~KeyboardInput()
{}

void KeyboardInput::onRegisterComponents(Scene& scene)
{
	scene.registerKeyboardInput(this);
}

void KeyboardInput::handleKeyDown(sf::Keyboard::Key key)
{
	evKeyDown(key);	
}
