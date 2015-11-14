#include "scenes-manager.hpp"
#include "storytext.hpp"
#include "menu.hpp"
#include <string>
#include <iostream>
#include "../map/level-description.hpp"
#include "../gameobjects/brick.hpp"
#include "../gameobjects/runge.hpp"
#include "../gameobjects/glaser.hpp"
#include "../gameobjects/npc.hpp"
#include "../gameobjects/coffee.hpp"
#include "../gameobjects/bizagi_cd.hpp"
#include "../gameobjects/caffeinelevel.hpp"
#include "../gameobjects/healthbar.hpp"
#include "../gameobjects/timer.hpp"
#include "../gameobjects/itemcounter.hpp"
#include "../map/layer.hpp"
#include "highscore.hpp"
#include "../gameobjects/kruse.hpp"
#include "../gameobjects/stroetmann.hpp"
#include "../gameobjects/setlx_cup.hpp"
#include "../gameobjects/apfeltasche.hpp"
#include "../gameobjects/c_exam.hpp"
#include "../gameobjects/hofmann.hpp"
#include "../gameobjects/uml_diagramm.hpp"
#include "../gameobjects/instrument_hofmann.hpp"
#include "../gameobjects/huebl.hpp"
#include "../gameobjects/math_solution.hpp"

using namespace theseus::scenes;
using namespace theseus::map;
using namespace theseus::gameobjects;
using namespace std;

string const INTRO = "Herzlich Willkommen beim DHBW-Labyrinth-Spiel!\n\n\n"
"ACHTUNG! An der DHBW gibt es aktuell besondere Vorkommnisse...\n"
"Die Dozenten und Professoren sind wuetend und wild geworden! Ein Virus ist aus\n"
"einem Computer ausgebrochen und hat saemtliche Dozenten und \n"
"Professoren infiziert. Diese haben nun ihre offene, freundliche \n"
"und nette Einstellung gegenueber den Studenten verloren und versuchen \n"
"nun alle Studenten zu exmatrikulieren. Bring ihnen ihre Gegenstaende\n"
"und Dokumente zurueck, um sie zu heilen!"
"\n\n\n"
"Beachte, dass DU der einzige bist, der die DHBW retten kann...\n"
"Doch pass auf, dass die Dozenten und Professoren dich nicht\n"
"exmatrikulieren! Absolviere alle 6 Level und befreie die Dozenten und Professoren\n"
"von dem Virus... Also sei vorsichtig und rette die DHBW!\n\n\n"
"Weiter mit <Leertaste>";

string const CONTROL = "Steuerung\n\n\n"
"Laufen:		W, A, S, D\n"
"Kaffee-Boost:	Leertaste\n"
"Pause:			ESC \n"
"Interagieren:	E\n"
"Bestaetigen:	Leertaste";

string const LEVEL1 = "Die erste Herausforderung ist es, Herrn Runge zu heilen.\n"
"Er war immer sehr nett und stellte keine besonders hohen Ansprueche. \n"
"Allerdings findet er gerade die Installations - CD seines Lieblingsprogramms Bizagi nicht.\n"
"Komme ihm nicht zu nahe!Das Virus und seine schlechte Laune fuehren dazu,\n"
"dass er keine Studenten sehen moechte.Falls er doch einen Studenten sieht, \n "
"versucht er diesen zu exmatrikulieren.\n"
"Also tritt ihm nicht zu nahe!\n"
"Suche die im DHBW - Gebaeude verschwundene Bizagi - Installations - CD und bringe\n"
"sie innerhalb der vorgegeben Zeit Herrn Runge zurueck,\n"
"der irgendwo innerhalb der DHBW herum irrt.\n"
"1. Suche die CD\n"
"2. Gebe die CD Herrn Runge";

string const LEVEL2 = "Herr Glaser geht oefter waehrend der Vorlesung die Kreide aus!\n"
"Aus Frust die Vorlesung nicht, wie gewohnt, durchfuehren zu koennen, rennt er planlos\n"
"durch die Gaenge.Das Virus macht ihn von einem liebevollen Menschen, zu einem Gegner,\n"
"der als Hobby Studenten exmatrikuliert.\n\n"
"Deine Aufgabe ist es, ihn zu heilen!Sammle dafuer in der vorgegebenen Zeit 3 Kreidestuecke\n"
"und bringe sie Herrn Glaser!";

string const LEVEL3 = "Herrn Huebl ist es langweilig...\n\n"
"Das Virus beeinflusst ihn so, dass er keine Studenten mehr sehen moechte\n"
"und deshalb diese exmatrikuliert.\n"
"Um ihn zu heilen, muessen ihm 5 Loesungen zu seinen Mathe-Aufgabenblaettern\n"
"uebergeben werden.\n";

string const LEVEL4 = "Puuh ist das wieder eine schlechte Luft hier! Im Gebaeude ist der Sauerstoffgehalt\n"
"ja im negativen Bereich... Haette Herr Hofmann sein Messgeraet, \n"
"wuerde dies nicht passieren. Aber er findet es nicht.\n"
"Ist Herr Hofmann ueberhaupt auf der Suche danach?\n"
"Auch er hat das Virus in sich.Trete ihm nicht zu nahe!\n"
"Finde das Messgeraet und beruhige / heile Herr Hofmann!\n"
"Pass auf, denn exmatrikulierte Studenten koennen Dich jetzt auch attackieren und\n"
"dir wertvolle Zeit zum vollenden des Levels stehlen!";

string const LEVEL5 = "Wo ist die denn die C-Klausur??? Ohne C-Klausur ist fuer Herr Kruse die Welt\n"
"nur halb so schoen...\n"
"Suche diese und bringe sie Herr Kruse zurueck!Meide den Kontakt zu deinen Kommilitonen,\n"
"da diese von Virus infiziert sein koennten.Falls du mit einem kranken von ihnen\n"
"in Kontakt kommst, wird du langsamer...\n\n"
"Hinweis: Finde eine Apfeltasche und uebergebe diesen Herrn Kruse.Dadurch ist er fuer\n"
"30 Sekunden abgelenkt und exmatrikuliert keinen Studenten.";

string const LEVEL6 = "Herr Stroetmann wurde am schlimmsten von dem Virus befallen...\n\n"
"Hinweis : Suche Frucktiv zu deiner eigenen Sicherheit!\n\n\n\n\n\n\n\n\n"
"Die Rettung der DHBW ist Nahe...";



void ScenesManager::run()
{
	{
		theseus::scenes::StoryText Storytext(game.getScreenResolution().x, game.getScreenResolution().y, LEVEL6);
		if (this->game.run(Storytext)) return;
	}
	if(this->loadStart())
	if(this->loadLevel1())
	if(this->loadLevel2())
	if(this->loadLevel3())
	if(this->loadLevel4())
	if(this->loadLevel5())
	if(this->loadLevel6()) {}

	this->loadHighScore();

}

bool ScenesManager::loadStart() {

	vector<string> buttons;

	buttons.push_back("Start");
	buttons.push_back("Quit");
	Menu menu(buttons, &(this->game));
	this->game.run(menu);

	if (menu.getLastKeyEvent() != sf::Keyboard::Return)
		return false;
	switch (menu.getSelectedItemIndex()) {
		case 0: return true;
		case 1: return false;
	}
	return false;
}

bool ScenesManager::loadLevel1() {
	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 80, Brick::HEIGHT * 40)));
	//set level specific object
	level->addFreeGameObject(unique_ptr<BizagiCD>(new BizagiCD()));

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
	//runge->setSize(sf::Vector2f (Brick::WIDTH, Brick::HEIGHT));
	level->setProf(move(runge));

	level->addRoom(move(mensa));

	auto man = unique_ptr<Player>(new Player(1000, 1000, lifePoints, 1));
	auto man_ptr = man.get();
	man->view().setSize(sf::Vector2f(game.getScreenResolution().x, game.getScreenResolution().y));
	man->setPosition(sf::Vector2f(500, 500));
	level->setPlayer(move(man));

	auto scene = Layer(move(level)).toScene();
	auto timer = unique_ptr<Timer>(new Timer(sf::Vector2f((float)game.getScreenResolution().x - 100, 15), 110));
	auto timer_ptr = timer.get();
	this->setHud(*scene, move(timer));
	scene->setCamera(man_ptr);

	auto status = this->game.run(*(scene));
	if(status || man_ptr->getLifePoints() == 0 || timer_ptr->getActualTime()) {
		this->playedTime = 0;
		return false;
	}
	else {
		this->lifePoints = man_ptr->getLifePoints();
		this->playedTime += timer_ptr->getActualTime();
		return true;
	}
}

bool ScenesManager::loadLevel2() {

	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 100, Brick::HEIGHT * 40)));
	//set level specific object
	level->addFreeGameObject(unique_ptr<BizagiCD>(new BizagiCD()));

	level->setMaxAmountOfStandardRooms(5);
	level->setMinRoomSize(sf::Vector2f(Brick::WIDTH * 5, Brick::HEIGHT * 5));

	level->setMaxRoomSize(sf::Vector2f(Brick::WIDTH * 10, Brick::HEIGHT * 10));

	//set amount of coffee
	for (int i = 0; i < 15; i++) {
		level->addFreeGameObject(unique_ptr<Coffee>(new Coffee()));
	}

	//set amount of students
	int x = 0;
	for (x = 0; x < 40; x++) {
		auto npc = unique_ptr<NPC>(new NPC);
		level->addFreeGameObject(move(npc));
	}

	//set professor Glaser
	auto glaser = unique_ptr<Glaser>(new Glaser);
	level->setProf(move(glaser));

	auto man = unique_ptr<Player>(new Player(1000, 1000, lifePoints, 1));
	auto man_ptr = man.get();
	man->view().setSize(sf::Vector2f(game.getScreenResolution().x, game.getScreenResolution().y));
	man->setPosition(sf::Vector2f(500, 500));
	level->setPlayer(move(man));

	auto scene = Layer(move(level)).toScene();
	auto timer = unique_ptr<Timer>(new Timer(sf::Vector2f((float)game.getScreenResolution().x - 100, 15), 110));
	auto timer_ptr = timer.get();
	this->setHud(*scene, move(timer));
	scene->setCamera(man_ptr);

	auto status = this->game.run(*(scene));
	if(status || man_ptr->getLifePoints() == 0 || timer_ptr->getActualTime()) {
		this->playedTime = 0;
		return false;
	}
	else {
		this->lifePoints = man_ptr->getLifePoints();
		this->playedTime += timer_ptr->getActualTime();
		return true;
	}
}
bool ScenesManager::loadLevel3() {
	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 100, Brick::HEIGHT * 50)));
	//set level specific object
	for (int i = 0; i < 5; i++) {
		level->addFreeGameObject(unique_ptr<MathSolution>(new MathSolution()));
	}
	level->setMaxAmountOfStandardRooms(5);
	level->setMinRoomSize(sf::Vector2f(Brick::WIDTH * 5, Brick::HEIGHT * 5));

	level->setMaxRoomSize(sf::Vector2f(Brick::WIDTH * 10, Brick::HEIGHT * 10));

	//set amount of coffee
	for (int i = 0; i < 15; i++) {
		level->addFreeGameObject(unique_ptr<Coffee>(new Coffee()));
	}

	//set amount of students
	int x = 0;
	for (x = 0; x < 40; x++) {
		auto npc = unique_ptr<NPC>(new NPC);
		level->addFreeGameObject(move(npc));
	}

	//set professor Huebl
	auto huebl = unique_ptr<Huebl>(new Huebl);
	level->setProf(move(huebl));

	auto man = unique_ptr<Player>(new Player(1000, 1000, lifePoints, 1));
	auto man_ptr = man.get();
	man->view().setSize(sf::Vector2f(game.getScreenResolution().x, game.getScreenResolution().y));
	man->setPosition(sf::Vector2f(500, 500));
	level->setPlayer(move(man));

	auto scene = Layer(move(level)).toScene();
	auto timer = unique_ptr<Timer>(new Timer(sf::Vector2f((float)game.getScreenResolution().x - 100, 15), 110));
	auto timer_ptr = timer.get();
	this->setHud(*scene, move(timer));
	scene->setCamera(man_ptr);

	auto status = this->game.run(*(scene));
	if(status || man_ptr->getLifePoints() == 0 || timer_ptr->getActualTime()) {
		this->playedTime = 0;
		return false;
	}
	else {
		this->lifePoints = man_ptr->getLifePoints();
		this->playedTime += timer_ptr->getActualTime();
		return true;
	}
}
bool ScenesManager::loadLevel4() {
	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 120, Brick::HEIGHT * 50)));
	//set level specific object
	level->addFreeGameObject(unique_ptr<Instrument>(new Instrument()));

	for (int i = 0; i < 5; i++) {
		level->addFreeGameObject(unique_ptr<UMLDiagramm>(new UMLDiagramm()));
	}

	level->setMaxAmountOfStandardRooms(6);
	level->setMinRoomSize(sf::Vector2f(Brick::WIDTH * 5, Brick::HEIGHT * 5));
	level->setMaxRoomSize(sf::Vector2f(Brick::WIDTH * 12, Brick::HEIGHT * 12));

	//set amount of coffee
	for (int i = 0; i < 15; i++) {
		level->addFreeGameObject(unique_ptr<Coffee>(new Coffee()));
	}

	//set amount of students
	int x = 0;
	for (x = 0; x < 40; x++) {
		auto npc = unique_ptr<NPC>(new NPC);
		level->addFreeGameObject(move(npc));
	}

	//set professor Hofmann
	auto hofmann = unique_ptr<Hofmann>(new Hofmann);
	level->setProf(move(hofmann));

	auto man = unique_ptr<Player>(new Player(1000, 1000, lifePoints, 1));
	auto man_ptr = man.get();
	man->view().setSize(sf::Vector2f(game.getScreenResolution().x, game.getScreenResolution().y));
	man->setPosition(sf::Vector2f(500, 500));
	level->setPlayer(move(man));

	auto scene = Layer(move(level)).toScene();
	auto timer = unique_ptr<Timer>(new Timer(sf::Vector2f((float)game.getScreenResolution().x - 100, 15), 110));
	auto timer_ptr = timer.get();
	this->setHud(*scene, move(timer));
	scene->setCamera(man_ptr);

	auto status = this->game.run(*(scene));
	if(status || man_ptr->getLifePoints() == 0 || timer_ptr->getActualTime()) {
		this->playedTime = 0;
		return false;
	}
	else {
		this->lifePoints = man_ptr->getLifePoints();
		this->playedTime += timer_ptr->getActualTime();
		return true;
	}
}
bool ScenesManager::loadLevel5() {
	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 120, Brick::HEIGHT * 50)));
	//set level specific object
	level->addFreeGameObject(unique_ptr<CExam>(new CExam()));

	for (int i = 0; i < 5; i++) {
		level->addFreeGameObject(unique_ptr<Apfeltasche>(new Apfeltasche()));
	}

	level->setMaxAmountOfStandardRooms(6);
	level->setMinRoomSize(sf::Vector2f(Brick::WIDTH * 5, Brick::HEIGHT * 5));

	level->setMaxRoomSize(sf::Vector2f(Brick::WIDTH * 12, Brick::HEIGHT * 12));

	//set amount of coffee
	for (int i = 0; i < 10; i++) {
		level->addFreeGameObject(unique_ptr<Coffee>(new Coffee()));
	}

	//set amount of students
	int x = 0;
	for (x = 0; x < 50; x++) {
		auto npc = unique_ptr<NPC>(new NPC);
		level->addFreeGameObject(move(npc));
	}

	//set professor Kruse
	auto kruse = unique_ptr<Kruse>(new Kruse);
	level->setProf(move(kruse));

	auto man = unique_ptr<Player>(new Player(1000, 1000, lifePoints, 1));
	auto man_ptr = man.get();
	man->view().setSize(sf::Vector2f(game.getScreenResolution().x, game.getScreenResolution().y));
	man->setPosition(sf::Vector2f(500, 500));
	level->setPlayer(move(man));

	auto scene = Layer(move(level)).toScene();
	auto timer = unique_ptr<Timer>(new Timer(sf::Vector2f((float)game.getScreenResolution().x - 100, 15), 110));
	auto timer_ptr = timer.get();
	this->setHud(*scene, move(timer));
	scene->setCamera(man_ptr);

	auto status = this->game.run(*(scene));
	if(status || man_ptr->getLifePoints() == 0 || timer_ptr->getActualTime()) {
		this->playedTime = 0;
		return false;
	}
	else {
		this->lifePoints = man_ptr->getLifePoints();
		this->playedTime += timer_ptr->getActualTime();
		return true;
	}

}
bool ScenesManager::loadLevel6() {
	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 120, Brick::HEIGHT * 50)));
	//set level specific object
	level->addFreeGameObject(unique_ptr<SetlxCup>(new SetlxCup()));

	level->setMaxAmountOfStandardRooms(6);
	level->setMinRoomSize(sf::Vector2f(Brick::WIDTH * 5, Brick::HEIGHT * 5));

	level->setMaxRoomSize(sf::Vector2f(Brick::WIDTH * 12, Brick::HEIGHT * 12));


	//set amount of coffee
	for (int i = 0; i < 15; i++) {
		level->addFreeGameObject(unique_ptr<Coffee>(new Coffee()));
	}

	//set amount of students
	int x = 0;
	for (x = 0; x < 100; x++) {
		auto npc = unique_ptr<NPC>(new NPC);
		level->addFreeGameObject(move(npc));
	}

	//set professor Stroetmann
	auto stroetmann = unique_ptr<Stroetmann>(new Stroetmann);
	level->setProf(move(stroetmann));

	auto man = unique_ptr<Player>(new Player(1000, 1000, lifePoints, 1));
	auto man_ptr = man.get();
	man->view().setSize(sf::Vector2f(game.getScreenResolution().x, game.getScreenResolution().y));
	man->setPosition(sf::Vector2f(500, 500));
	level->setPlayer(move(man));

	auto scene = Layer(move(level)).toScene();
	auto timer = unique_ptr<Timer>(new Timer(sf::Vector2f((float)game.getScreenResolution().x - 100, 15), 110));
	auto timer_ptr = timer.get();
	this->setHud(*scene, move(timer));
	scene->setCamera(man_ptr);

	auto status = this->game.run(*(scene));
	if(status || man_ptr->getLifePoints() == 0 || timer_ptr->getActualTime()) {
		this->playedTime = 0;
		return false;
	}
	else {
		this->lifePoints = man_ptr->getLifePoints();
		this->playedTime += timer_ptr->getActualTime();
		return true;
	}

}

void ScenesManager::setHud(theseus::engine::Scene& scene, std::unique_ptr<theseus::gameobjects::Timer> timer) {
	auto caffeineLevel = unique_ptr<CaffeineLevel>(new CaffeineLevel(sf::Vector2f((float)game.getScreenResolution().x, 15)));
	scene.addGameObject(move(caffeineLevel));

	auto healthbar = unique_ptr<HealthBar>(new HealthBar(sf::Vector2f(15, 15)));
	scene.addGameObject(move(healthbar));

	scene.addGameObject(move(timer));

	auto itemCounter = unique_ptr<ItemCounter>(new ItemCounter(sf::Vector2f((float)game.getScreenResolution().x - 100, (float)game.getScreenResolution().y - 40)));
	scene.addGameObject(move(itemCounter));
}

void ScenesManager::loadHighScore() {
	theseus::scenes::Highscore highscore(game.getScreenResolution().x, game.getScreenResolution().y, playedTime);
	game.run(highscore);
}
