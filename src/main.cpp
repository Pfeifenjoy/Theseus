#include "engine/game.hpp"
#include "engine/scene.hpp"
#include "engine/texturemanager.hpp"
#include "gameobjects/ball.hpp"

#include <iostream>
#include <memory>

using namespace std;
using namespace theseus::engine;
using namespace theseus::gameobjects;

int main()
{
    cout << "Hello." << endl;

    // Load the game
    theseus::engine::Game game;

    // Create the first scene
    unique_ptr<Scene> initScene = unique_ptr<Scene>(new Scene());

    // load the textures
    TextureManager::instance().loadTexture("ball.png");

    // Populate it with a ball GameObject
    auto ball = unique_ptr<Ball>(new Ball);
    initScene->addGameObject(move(ball));

    // Start the game with that scene
    game.run(move(initScene));

    // end
    TextureManager::reset();
    return 0;
}
