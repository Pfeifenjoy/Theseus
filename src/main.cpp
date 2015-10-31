#include "engine/game.hpp"
#include "engine/scene.hpp"
#include "engine/texturemanager.hpp"
#include "gameobjects/ball.hpp"
#include "gameobjects/character.hpp"
#include "gameobjects/map/Layer.hpp"

#include <iostream>
#include <memory>

using namespace std;
using namespace theseus::engine;
using namespace theseus::gameobjects;
using namespace theseus::gameobjects::map;

int main()
{
    cout << "Hello." << endl;
	Layer layer(100, 40);
	cout << layer << endl;


//    // Load the game
//    theseus::engine::Game game;
//
//    // Create the first scene
//    unique_ptr<Scene> initScene = unique_ptr<Scene>(new Scene());
//
//    // load the textures
//    TextureManager::instance().loadTexture("player.png");
//
//    // Populate it with some game objects
//    auto man = unique_ptr<Character>(new Character);
//    initScene->addGameObject(move(man));
//
//    // Start the game with that scene
//    game.run(move(initScene));
//
//    // end
//    TextureManager::reset();
    return 0;
}
