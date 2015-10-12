#include "update.hpp"
#include "../scene.hpp"

using namespace theseus::engine::components;

Update::Update()
{
	baseInitialized.setCallback(std::function<void(Update*)>(&Update::onBaseInitialized), this);
	evBaseInitialized.subscribe(baseInitialized);
}

void Update::onBaseInitialized()
{
	scene().addUpdate(this);
}
