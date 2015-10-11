#include "engine/game.hpp"
#include "scenes/examplescene.hpp"

#include <iostream>
#include <memory>

using namespace std;
using namespace theseus::engine;
using namespace theseus::scenes;

int main()
{
    cout << "Hello." << endl;

    // Load the game
    theseus::engine::Game game;

    // Load the first scene
    unique_ptr<Scene> initScene(new ExampleScene(game));

    // Start the game with that scene
    game.run(move(initScene));

    return 0;

}
