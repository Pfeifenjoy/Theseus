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
	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 20, Brick::HEIGHT * 20)));

	level->addFreeGameObject(unique_ptr<BizagiCD> (new BizagiCD()));
	level->setMaxAmountOfStandardRooms(1);
	level->setMinRoomSize(sf::Vector2f(Brick::WIDTH * 15, Brick::HEIGHT * 15));
	level->setMaxRoomSize(sf::Vector2f(Brick::WIDTH * 15, Brick::HEIGHT * 15));

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


	unique_ptr<LevelDescription> description = createLevel1();


	int x = 0;
	for(x = 0; x < 100; x++) {
		auto npc = unique_ptr<NPC>(new NPC);
		npc->setPosition(sf::Vector2f(rand() % 10000,rand() % 10000));
		description->addFreeGameObject(move(npc));
	}
	Layer layer(move(description));
	cout << layer << endl;
	initScene = layer.toScene();

	auto man = unique_ptr<Player>(new Player);
	auto man_ptr = man.get();
	man->setPosition(sf::Vector2f (65, 65));
	initScene->addGameObject(move(man));
	initScene->setCamera(man_ptr);

	//Testing if the gameobject images are correct ---------------------

	auto uml = unique_ptr<UMLDiagramm>(new UMLDiagramm(sf::Vector2f(32, 64)));
	initScene->addGameObject(move(uml));

	auto meter = unique_ptr<Instrument>(new Instrument(sf::Vector2f(32, 128)));
	initScene->addGameObject(move(meter));

	auto solution = unique_ptr<MathSolution>(new MathSolution(sf::Vector2f(32, 192)));
	initScene->addGameObject(move(solution));

	auto fructiv = unique_ptr<Fructiv>(new Fructiv(sf::Vector2f(32, 254)));
	initScene->addGameObject(move(fructiv));

	auto coffee = unique_ptr<Coffee>(new Coffee(sf::Vector2f(64, 64)));
	initScene->addGameObject(move(coffee));

	auto chalk = unique_ptr<Chalk>(new Chalk(sf::Vector2f(64, 128)));
	initScene->addGameObject(move(chalk));

	auto cexam = unique_ptr<CExam>(new CExam(sf::Vector2f(64, 192)));
	initScene->addGameObject(move(cexam));

	auto apple = unique_ptr<Apfeltasche>(new Apfeltasche(sf::Vector2f(64, 254)));
	initScene->addGameObject(move(apple));

	auto cup = unique_ptr<SetlxCup>(new SetlxCup(sf::Vector2f(32, 318)));
	initScene->addGameObject(move(cup));


	auto throwing = unique_ptr<ThrowingCup>(new ThrowingCup(sf::Vector2f(32, 382)));
	initScene->addGameObject(move(throwing));

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
