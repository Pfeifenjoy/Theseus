#include "update.hpp"
#include "../scene.hpp"

using namespace std;
using namespace theseus::engine::components;

Update::Update()
{
	evBaseInitialized.subscribe(bind(&Update::onBaseInitialized, this));
}

void Update::onBaseInitialized()
{
	scene().addUpdate(this);
}

void Update::doUpdate(float passedTime)
{
	evOnUpdate(passedTime);
}
