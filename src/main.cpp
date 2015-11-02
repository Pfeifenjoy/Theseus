#include "engine/game.hpp"
#include "engine/scene.hpp"
#include "engine/texturemanager.hpp"
#include "gameobjects/ball.hpp"
#include "gameobjects/character.hpp"
#include "gameobjects/wall.hpp"
#include "gameobjects/coffee.hpp"
#include "gameobjects/chalk.hpp"
#include "gameobjects/math_solution.hpp"
#include "gameobjects/instrument_hofmann.hpp"
#include "gameobjects/uml_diagramm.hpp"
#include "gameobjects/apfeltasche.hpp"
#include "gameobjects/c_exam.hpp"
#include "gameobjects/setlx_cup.hpp"
#include "gameobjects/fructiv.hpp"
#include "gameobjects/table.hpp"
#include "gameobjects/floor.hpp"
#include "gameobjects/player.hpp"
#include "gameobjects/npc.hpp"

#include <iostream>
#include <memory>

using namespace std;
using namespace theseus::engine;
using namespace theseus::gameobjects;

int main()
{
	cout << "Hello." << endl;
	srand((unsigned)time(NULL));

	// Load the game
	theseus::engine::Game game;

	// Create the first scene
	unique_ptr<Scene> initScene = unique_ptr<Scene>(new Scene());

	// load the textures
	TextureManager::instance().loadTexture("player.png");
	TextureManager::instance().loadTexture("player2.png");
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
	TextureManager::instance().loadTexture("ball.png");
	TextureManager::instance().loadTexture("floor_black.png");


	// Populate it with some game objects
	auto wall = unique_ptr<Wall>(new Wall(1, sf::Vector2f(50, 50), sf::Vector2f(320, 64)));
	initScene->addGameObject(move(wall));

	auto man = unique_ptr<Player>(new Player);
	initScene->addGameObject(move(man));
	
	auto npc = unique_ptr<NPC>(new NPC);
	npc->setPosition(sf::Vector2f(200, 200));
	initScene->addGameObject(move(npc));

	auto floor = unique_ptr<Floor>(new Floor(sf::Vector2f(0,0), sf::Vector2f(500,500)));
	initScene->addGameObject(move(floor));

	// Start the game with that scene
	game.run(move(initScene));

	// end
	TextureManager::reset();
	return 0;
}
