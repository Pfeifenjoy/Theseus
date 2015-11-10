#include "scenes-manager.hpp"
#include "intro.hpp"
#include "menu.hpp"
#include <string>
#include <iostream>
#include "../map/level-description.hpp"
#include "../gameobjects/brick.hpp"
#include "../gameobjects/runge.hpp"
#include "../gameobjects/npc.hpp"
#include "../gameobjects/coffee.hpp"
#include "../gameobjects/bizagi_cd.hpp"
#include "../map/layer.hpp"

using namespace theseus::scenes;
using namespace theseus::map;
using namespace theseus::gameobjects;
using namespace std;

ScenesManager::ScenesManager() {
	{
		Intro intro(game.getScreenResolution().x, game.getScreenResolution().y);
		this->game.run(intro);
	}
	this->loadStart();

}

void ScenesManager::loadStart() {

	vector<string> buttons;

	buttons.push_back("Start");
	buttons.push_back("Options");
	buttons.push_back("Quit");
	Menu menu(buttons, &(this->game));
	this->game.run(menu);

	if(menu.getLastKeyEvent() != sf::Keyboard::Return)
		return;
	switch(menu.getSelectedItemIndex()) {
		case 0: this->loadLevel1(); break;
		case 1: break;
		case 2: break;
	}
}

void ScenesManager::loadLevel1() {
	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 80, Brick::HEIGHT * 40)));
	//set level specific object
	level->addFreeGameObject(unique_ptr<BizagiCD> (new BizagiCD()));

	level->setMaxAmountOfStandardRooms(5);
	level->setMinRoomSize(sf::Vector2f(Brick::WIDTH * 5, Brick::HEIGHT * 5));

	level->setMaxRoomSize(sf::Vector2f(Brick::WIDTH * 10, Brick::HEIGHT * 10));

	//set amount of coffee
	for (int i = 0; i < 15; i++) {
		level->addFreeGameObject(unique_ptr<Coffee>(new Coffee()));
	}

	//set amount of students
	int x = 0;
	for (x = 0; x < 30; x++) {
		auto npc = unique_ptr<NPC>(new NPC);
		level->addFreeGameObject(move(npc));
	}

	unique_ptr<RoomDescription> mensa(new RoomDescription(Brick::WIDTH * 10, Brick::HEIGHT * 10));
	//set professor Runge
	auto runge = unique_ptr<Runge>(new Runge);
	mensa->addGameObject(move(runge));

	level->addRoom(move(mensa));

	auto scene = Layer(move(level)).toScene();

	auto man = unique_ptr<Player>(new Player);
	auto man_ptr = man.get();
	man->view().setSize(sf::Vector2f(game.getScreenResolution().x, game.getScreenResolution().y));
	man->setPosition(sf::Vector2f (65, 65));
	scene->addGameObject(move(man));
	scene->setCamera(man_ptr);

	this->game.run(*(scene));

	scene->checkFinished();
}
