#include "base.hpp"
#include "../scene.hpp"
#include "../game.hpp"

using namespace theseus::engine;
using namespace theseus::engine::components;

bool Base::isInitialized() const
{
	return myscene != nullptr;
}

Scene& Base::scene()
{
	return *myscene;
}

const Scene& Base::scene() const
{
	return *myscene;
}

Game& Base::game()
{
	return myscene->game();
}

const Game& Base::game() const
{
	return myscene->game();
}
