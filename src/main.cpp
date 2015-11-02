#include "engine/game.hpp"
#include "engine/scene.hpp"
#include "engine/texturemanager.hpp"
#include "gameobjects/ball.hpp"
#include "gameobjects/character.hpp"
#include "gameobjects/map/layer.hpp"
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
#include "gameobjects/button.hpp"
#include "scenes/menu.hpp"

#include <iostream>
#include <memory>

using namespace std;
using namespace theseus::engine;
using namespace theseus::gameobjects;
using namespace theseus::gameobjects::map;

int main()
{
	cout << "Hello." << endl;
	srand((unsigned)time(NULL));

//	// Load the game
	theseus::engine::Game game;
//
	// Create the first scene
	unique_ptr<Scene> initScene = unique_ptr<Scene>(new Scene());
//
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


	Layer layer(100, 40);
	auto objects = layer.getGameObjects();
	cout << objects.size() <<endl;
	for(auto& object: objects) {
		initScene->addGameObject(move(object));
	}
	cout << layer << endl;

	auto man = unique_ptr<Player>(new Player);
	initScene->addGameObject(move(man));

	int x = 0;
	for(x = 0; x < 10000; x++) {
		auto npc = unique_ptr<NPC>(new NPC);
		npc->setPosition(sf::Vector2f(rand() % 1000, rand() % 1000));
		initScene->addGameObject(move(npc));
	}

	auto floor = unique_ptr<Floor>(new Floor(sf::Vector2f(0,0), sf::Vector2f(100 * Brick::WIDTH, 40 * Brick::HEIGHT)));
	initScene->addGameObject(move(floor));


	vector<std::string >  menuItems;
	menuItems.push_back("Spiel starten!");
	menuItems.push_back("Optionen");
	menuItems.push_back("Beenden");

	vector<unique_ptr<Scene> > scenes;
	scenes.push_back(move(initScene));


	unique_ptr<Menu> menuScene = unique_ptr<Menu>(new Menu(500, 500, menuItems, scenes, &game));

	//Start the game with that scene
	game.run(move(menuScene));

	TextureManager::reset();
	return 0;
}
