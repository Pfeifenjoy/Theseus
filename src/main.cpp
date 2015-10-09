#include "engine/game.hpp"
#include "scenes/examplescene.hpp"

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello." << endl;

    // Start the game
    theseus::engine::Game game;
    theseus::scenes::ExampleScene initialScene(game);
    game.run(initialScene);

    return 0;

}
