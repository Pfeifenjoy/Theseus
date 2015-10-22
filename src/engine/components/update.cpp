#include "update.hpp"
#include "../scene.hpp"

using namespace std;
using namespace std::placeholders;
using namespace theseus::engine::components;

Update::Update()
{
	evRegisterComponents.subscribe(bind(&Update::onRegisterComponents, this, _1));
}

void Update::onRegisterComponents(Scene& scene)
{
	scene.addUpdate(this);
}

void Update::doUpdate(float passedTime)
{
	evOnUpdate(passedTime);
}
