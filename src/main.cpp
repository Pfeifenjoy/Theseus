#include "engine/game.hpp"
#include "engine/scene.hpp"
#include "engine/texturemanager.hpp"
#include "gameobjects/ball.hpp"
#include "gameobjects/character.hpp"
#include "map/layer.hpp"
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
#include "gameobjects/textfield.hpp"
#include "scenes/menu.hpp"
#include "gameobjects/bizagi_cd.hpp"
#include "gameobjects/throwing_cup.hpp"
#include "gameobjects/healthbar.hpp"
#include "gameobjects/timer.hpp"
#include "gameobjects/itemcounter.hpp"
#include "gameobjects/caffeinelevel.hpp"
#include "map/level-description.hpp"

#include <iostream>
#include <memory>

using namespace std;
using namespace theseus::engine;
using namespace theseus::gameobjects;
using namespace theseus::map;

unique_ptr<LevelDescription> createLevel1() {
	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 40, Brick::HEIGHT * 40)));
	//set level specific object
	level->addFreeGameObject(unique_ptr<BizagiCD> (new BizagiCD()));

	level->setMaxAmountOfStandardRooms(1);
	level->setMinRoomSize(sf::Vector2f(Brick::WIDTH * 3, Brick::HEIGHT * 3));
	level->setMaxRoomSize(sf::Vector2f(Brick::WIDTH * 15, Brick::HEIGHT * 15));

	//set amount of coffee
	for (int i = 0; i < 10; i++) {
		level->addFreeGameObject(unique_ptr<Coffee>(new Coffee()));
	}

	//set amount of students
	int x = 0;
	for (x = 0; x < 25; x++) {
		auto npc = unique_ptr<NPC>(new NPC);
		npc->setPosition(sf::Vector2f(rand() % 10000, rand() % 10000));
		level->addFreeGameObject(move(npc));
	}

	return level;
}

unique_ptr<LevelDescription> createLevel2() {
	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 40, Brick::HEIGHT * 40)));

	//level specific Object
	level->addFreeGameObject(unique_ptr<Chalk>(new Chalk()));

	level->setMaxAmountOfStandardRooms(4);
	level->setMaxRoomSize(sf::Vector2f(Brick::HEIGHT * 3, Brick::WIDTH * 4));
	level->setMinRoomSize(sf::Vector2f(Brick::HEIGHT * 2, Brick::WIDTH * 2));
	
	//set amount of coffee
	for (int i = 0; i < 10; i++) {
			level->addFreeGameObject(unique_ptr<Coffee>(new Coffee()));
		}
	//set amount of students
	for (int x = 0; x < 25; x++) {
		auto npc = unique_ptr<NPC>(new NPC);
		npc->setPosition(sf::Vector2f(rand() % 10000, rand() % 10000));
		level->addFreeGameObject(move(npc));
	}

	return level;
}

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
	TextureManager::instance().loadTexture("floor_red.png");
	TextureManager::instance().loadTexture("gras.png");
	TextureManager::instance().loadTexture("item_table.png");
	TextureManager::instance().loadTexture("item_table2.png");
	TextureManager::instance().loadTexture("item_level_4_UML.png");
	TextureManager::instance().loadTexture("item_level_3_solutions.png");
	TextureManager::instance().loadTexture("item_level_4_meter.png");
	TextureManager::instance().loadTexture("item_level_6_fructiv.png");
	TextureManager::instance().loadTexture("item_coffee.png");
	TextureManager::instance().loadTexture("item_level_2_chalk.png");
	TextureManager::instance().loadTexture("item_level_5_exam.png");
	TextureManager::instance().loadTexture("item_level_5_appleturnover.png");
	TextureManager::instance().loadTexture("item_level_6_cup.png");
	TextureManager::instance().loadTexture("item_level_1_bizagi_cd.png");
	TextureManager::instance().loadTexture("item_level_6_cup2.png");
	TextureManager::instance().loadTexture("heart.png");


	unique_ptr<LevelDescription> description = createLevel2();


	
	Layer layer(move(description));
	cout << layer << endl;
	initScene = layer.toScene();

	auto man = unique_ptr<Player>(new Player);
	auto man_ptr = man.get();
	man->setPosition(sf::Vector2f (65, 65));
	initScene->addGameObject(move(man));
	initScene->setCamera(man_ptr);

	//Testing if the gameobject images are correct ---------------------

	

	auto table = unique_ptr<Table>(new Table(sf::Vector2f(32, 446), 0));
	initScene->addGameObject(move(table));

	auto table2 = unique_ptr<Table>(new Table(sf::Vector2f(96, 446), 1));
	initScene->addGameObject(move(table2));

	// HUD

	auto healthbar = unique_ptr<HealthBar>(new HealthBar(sf::Vector2f(15, 15), 3));
	initScene->addGameObject(move(healthbar));

	auto timer = unique_ptr<Timer>(new Timer(sf::Vector2f((float) game.getScreenResolution().x - 100, 15), 10));
	initScene->addGameObject(move(timer));

	auto itemCounter = unique_ptr<ItemCounter>(new ItemCounter(sf::Vector2f((float)game.getScreenResolution().x - 100, (float)game.getScreenResolution().y - 40), 3));
	initScene->addGameObject(move(itemCounter));

	auto caffeineLevel = unique_ptr<CaffeineLevel>(new CaffeineLevel(sf::Vector2f((float)game.getScreenResolution().x, 15), 24, 115));
	initScene->addGameObject(move(caffeineLevel));

	//---------------------------------------------------------------------------------

	vector<std::string >  menuItems;
	menuItems.push_back("Spiel starten!");
	menuItems.push_back("Optionen");
	menuItems.push_back("Beenden");

	vector<unique_ptr<Scene> > scenes;
	scenes.push_back(move(initScene));


	unique_ptr<Menu> menuScene = unique_ptr<Menu>(new Menu(menuItems, scenes, &game));

	//Start the game with that scene
	game.run(move(menuScene));


	TextureManager::reset();
	return 0;
}
