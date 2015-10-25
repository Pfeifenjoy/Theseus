#include "update.hpp"
#include "../scene.hpp"

using namespace std;
using namespace std::placeholders;
using namespace theseus::engine::components;

Update::Update()
{
	evRegisterComponents.subscribe(bind(&Update::onRegisterComponents, this, _1));
	evUnregisterComponents.subscribe(bind(&Update::onUnregisterComponents, this, _1));
}

Update::~Update()
{}

void Update::onRegisterComponents(Scene& scene)
{
	scene.registerUpdate(this);
}

void Update::onUnregisterComponents(Scene& scene)
{
	scene.unregisterUpdate(this);
}

void Update::doUpdate(float passedTime)
{
	evOnUpdate(passedTime);
}
