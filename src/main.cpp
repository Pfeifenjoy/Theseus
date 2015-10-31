#include "engine/game.hpp"
#include "engine/scene.hpp"
#include "engine/texturemanager.hpp"
#include "gameobjects/ball.hpp"
#include "gameobjects/character.hpp"
#include "gameobjects/wall.hpp"

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
	TextureManager::instance().loadTexture("player.png");
	TextureManager::instance().loadTexture("wall_horizontal.png");
	TextureManager::instance().loadTexture("wall_vertical.png");
	TextureManager::instance().loadTexture("wall_edge_left_bottom.png");
	TextureManager::instance().loadTexture("wall_edge_left_top.png");
	TextureManager::instance().loadTexture("wall_edge_right_bottom.png");
	TextureManager::instance().loadTexture("wall_edge_right_top.png");
	TextureManager::instance().loadTexture("wall_left_middle.png");
	TextureManager::instance().loadTexture("wall_left_end.png");
	TextureManager::instance().loadTexture("wall_right_middle.png");
	TextureManager::instance().loadTexture("wall_right_end.png");
	TextureManager::instance().loadTexture("wall_bottom_end.png");
	TextureManager::instance().loadTexture("wall_top_end.png");
	TextureManager::instance().loadTexture("wall_cross.png");
	TextureManager::instance().loadTexture("wall_T_cross.png");
	TextureManager::instance().loadTexture("wall_T_upsidedown_cross.png");

	// Populate it with some game objects
	auto wall = unique_ptr<Wall>(new Wall(1, sf::Vector2f(50, 50), sf::Vector2f(320, 64)));
	initScene->addGameObject(move(wall));

	auto man = unique_ptr<Character>(new Character);
	initScene->addGameObject(move(man));

	// Start the game with that scene
	game.run(move(initScene));

	// end
	TextureManager::reset();
	return 0;
}
