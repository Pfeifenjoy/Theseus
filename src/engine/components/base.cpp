/**
 * Autor: Tobias Dorra
 */
#include "base.hpp"

using namespace theseus::engine;
using namespace theseus::engine::components;

theseus::engine::components::Base::~Base()
{}

void Base::registerComponents(Scene& scene)
{
	evRegisterComponents(scene);
}
		
void Base::refreshComponentRegistrations(Scene& scene)
{
	evUpdateComponentRegistrations(scene);
}

void Base::unregisterComponents(Scene& scene)
{
	evUnregisterComponents(scene);
}

void Base::selfDestruct()
{
	theEndIsNear = true;
}

bool Base::needsDestruction() const
{
	return theEndIsNear;
}
