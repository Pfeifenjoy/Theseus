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
#include "../gameobjects/chalk.hpp"
#include "../engine/end-of-Time.hpp"


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
"von dem Virus... Also sei vorsichtig und rette die DHBW!"
"\n\n\nWeiter mit <Leertaste>";

string const CONTROL = "[Steuerung]\n\n\n"
"Laufen:  " "<W, A, S, D>\n\n"
"Kaffee-Boost:  " "<Leertaste>\n\n"
"Pause:  " "<ESC>\n\n"
"Interagieren:  " "<E>\n\n"
"Bestaetigen:  ""<Leertaste>\n\n\n"
"\n\n\nWeiter mit <Leertaste>";

string const LEVEL1 = "[Level 1]\n\n\n"
"Die erste Herausforderung ist es, Herrn Runge zu heilen.\n"
"Er war immer sehr nett und engagiert. \n"
"Zur Zeit findet er gerade die Installations-CD für sein Lieblingsprogramms Bizagi nicht.\n"
"Komme ihm nicht zu nahe! Das Virus und seine schlechte Laune fuehren dazu,\n"
"dass er keine Studenten sehen moechte. Falls er doch einen Studenten sieht, \n "
"versucht er diesen zu exmatrikulieren.\n"
"Also komm ihm nicht zu nahe!\n"
"Suche in der DHBW nach der verschwundenen Bizagi-Installations- CD und bringe\n"
"sie innerhalb der vorgegeben Zeit zu Herrn Runge,\n"
"der irgendwo innerhalb der DHBW herum irrt.\n\n"
"Aufgabe:\n"
"1. Suche die CD\n"
"2. Gib die CD Herrn Runge"
"\n\n\nWeiter mit <Leertaste>";

string const LEVEL2 = "[Level 2]\n\n\n"
"Herrn Glaser geht oefter waehrend der Vorlesung die Kreide aus!\n"
"Aus Frust die Vorlesung nicht, wie gewohnt, durchfuehren zu koennen, rennt er planlos\n"
"durch die Gaenge. Das Virus macht ihn von einem liebevollen Menschen, zu einem Gegner,\n"
"der als Hobby Studenten exmatrikuliert.\n\n"
"Deine Aufgabe ist es, ihn zu heilen! Sammle dafuer in der vorgegebenen Zeit 3 Kreidestuecke\n"
"und bringe sie Herrn Glaser!\n\n"
"Aufgabe:\n"
"1. Suche 3 Kreidestuecke\n"
"2. Gib die Kreidestuecke Herrn Glaser"
"\n\n\n"
"\n\n\nWeiter mit <Leertaste>";

string const LEVEL3 = "[Level 3]\n\n\n"
"Herrn Huebl ist es langweilig...\n\n"
"Das Virus beeinflusst ihn so, dass er keine Studenten mehr sehen moechte\n"
"und deshalb diese exmatrikuliert.\n"
"Um ihn zu heilen, muessen ihm 5 Loesungen zu seinen Mathe-Aufgabenblaettern\n"
"uebergeben werden.\n\n"
"Aufgabe:\n"
"1. Uebergib Herrn Huebl 5 Loesungen"
"\n\n\n\n\n"
"\n\n\nWeiter mit <Leertaste>";

string const LEVEL4 = "[Level 4]\n\n\n"
"Puuh ist das wieder eine schlechte Luft hier! Im Gebaeude ist der Sauerstoffgehalt\n"
"ja im negativen Bereich... Haette Herr Hofmann sein Messgeraet, \n"
"wuerde dies nicht passieren. Aber er findet es nicht!\n"
"Ist Herr Hofmann ueberhaupt auf der Suche danach?\n"
"Auch er ist infiziert. Komm ihm nicht zu nahe!\n"
"Finde das Messgeraet und heile Herrn Hofmann!\n"
"Pass auf, denn exmatrikulierte Studenten koennen Dich jetzt auch attackieren und\n"
"dir wertvolle Zeit zum vollenden des Levels stehlen!\n\n"
"Aufgabe:\n"
"1. Bring Herrn Hofmann sein Messgeraet"
"\n\n\n"
"\n\n\nWeiter mit <Leertaste>";

string const LEVEL5 = "[Level 5]\n\n\n"
"Wo ist die denn die C-Klausur??? Ohne C-Klausur ist fuer Herrn Kruse die Welt\n"
"nur halb so schoen...\n"
"Suche diese und bringe sie Herrn Kruse zurueck! Meide den Kontakt zu deinen Kommilitonen!\n"
"Diese koennen ebenfalls vom Virus infiziert sein. Falls du mit einem Infizierten\n"
"in Kontakt kommst, wird du langsamer...\n\n"
"Hinweis: Finde eine Apfeltasche und uebergebe diesen Herrn Kruse. Dadurch ist er fuer\n"
"30 Sekunden abgelenkt und exmatrikuliert keinen Studenten.\n\n"
"Aufgabe:\n"
"1. Bring Herrn Kruse die C-Klausur"
"\n\n\n"
"\n\n\nWeiter mit <Leertaste>";

string const LEVEL6 = "[Level 6]\n\n\n"
"Herr Stroetmann wurde am schlimmsten von dem Virus befallen...\n\n"
"Jeder, der einmal in seiner Vorlesung gewesen ist, kennt sicherlich seine\n"
"geliebte 'I love SetlX'-Tasse. Und genau diese ist verschwunden.\n"
"Aus diesem Grund ist Herr Stroetmann veraergert und exmatrikuliert Studenten!\n"
"Finde und bring ihm seine Tasse und Herr Stroetmann wird geheilt.\n\n"
"Hinweis: Suche eine Flasche Frucktiv zu deiner eigenen Sicherheit!\n\n"
"Aufgabe:\n"
"1. Bring Herrn Stroetmann seine 'I love SetlX'-Tasse"
"\n"
"Die Rettung der DHBW ist Nahe...\n\n"
"\n\n\nWeiter mit <Leertaste>";



void ScenesManager::run()
{
	{
		theseus::scenes::StoryText Storytext(game.getScreenResolution().x, game.getScreenResolution().y, INTRO);
		if (this->game.run(Storytext)) return;
	}
	{
		theseus::scenes::StoryText Storytext(game.getScreenResolution().x, game.getScreenResolution().y, CONTROL);
		if (this->game.run(Storytext)) return;
	}
	while(true) {
		if(this->loadStart())
		if(this->selectCharacter())
		if(this->loadLevel1())
		if(this->loadLevel2())
		if(this->loadLevel3())
		if(this->loadLevel4())
		if(this->loadLevel5())
		if(this->loadLevel6()) {}

		this->loadHighScore();
	}

}

bool ScenesManager::loadStart() {

	vector<string> buttons;

	buttons.push_back("Start");
	buttons.push_back("Quit");
	Menu menu(buttons, &(this->game));
	this->game.run(menu);

	switch (menu.getSelectedItemIndex()) {
		case 0: return true;
		case 1: throw theseus::engine::EndOfTime();
	}
	return false;
}
void ScenesManager::loadPause(theseus::map::Level& level) {
	while(level.getLastKey() == sf::Keyboard::Escape) {
		vector<string> buttons;

		buttons.push_back("Continue");
		buttons.push_back("Quit");
		Menu menu(buttons, &(this->game));
		this->game.run(menu);
		if(menu.getSelectedItemIndex() == 0) {
			level.setUnfinished();
			this->game.run(level);
		}
		else throw theseus::engine::EndOfTime();

	}
}

bool ScenesManager::selectCharacter() // added by Leon Mutschke on 13.11.15
{
	vector<string> buttonsCharacter;

	buttonsCharacter.push_back("Male");
	buttonsCharacter.push_back("Female");
	Menu menu(buttonsCharacter, &(this->game));
	this->game.run(menu);

	switch (menu.getSelectedItemIndex()) {
		case 0: male=true; break;
		case 1: male=false;
	}
	return true;
}


bool ScenesManager::loadLevel1() {

	{
		theseus::scenes::StoryText Storytext(game.getScreenResolution().x, game.getScreenResolution().y, LEVEL1);
		this->game.run(Storytext);
	}

	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 80, Brick::HEIGHT * 40)));
	//set level specific object
	level->addFreeGameObject(unique_ptr<BizagiCD>(new BizagiCD()));

	string bizagicd = "item_level_1_bizagi_cd.png";

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
	man_ptr->setMale(male);


	auto scene = Layer(move(level)).toScene();
	auto timer = unique_ptr<Timer>(new Timer(sf::Vector2f((float)game.getScreenResolution().x - 125, 15), 180));
	auto timer_ptr = timer.get();
	this->setHud(*scene, move(timer), bizagicd);
	scene->setCamera(man_ptr);

	this->game.run(*(scene));
	this->loadPause(*(scene));
	if(man_ptr->getLifePoints() == 0 || timer_ptr->getActualTime() <= 0) {
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

	{
		theseus::scenes::StoryText Storytext(game.getScreenResolution().x, game.getScreenResolution().y, LEVEL2);
		this->game.run(Storytext);
	}

	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 100, Brick::HEIGHT * 40)));
	//set level specific object
	for (int i = 0; i < 10; ++i) {
		level->addFreeGameObject(unique_ptr<Chalk>(new Chalk()));
	}

	string chalk = "item_level_2_chalk.png";

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

	auto man = unique_ptr<Player>(new Player(1000, 1000, lifePoints, 3));
	auto man_ptr = man.get();
	man->view().setSize(sf::Vector2f(game.getScreenResolution().x, game.getScreenResolution().y));
	man->setPosition(sf::Vector2f(500, 500));
	level->setPlayer(move(man));
	man_ptr->setMale(male);

	auto scene = Layer(move(level)).toScene();
	auto timer = unique_ptr<Timer>(new Timer(sf::Vector2f((float)game.getScreenResolution().x - 125, 15), 240));
	auto timer_ptr = timer.get();
	this->setHud(*scene, move(timer), chalk);
	scene->setCamera(man_ptr);

	this->game.run(*(scene));
	this->loadPause(*(scene));
	if(man_ptr->getLifePoints() == 0 || timer_ptr->getActualTime() <= 0) {
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

	{
		theseus::scenes::StoryText Storytext(game.getScreenResolution().x, game.getScreenResolution().y, LEVEL3);
		this->game.run(Storytext);
	}

	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 100, Brick::HEIGHT * 50)));
	//set level specific object
	for (int i = 0; i < 3; i++) {
		level->addFreeGameObject(unique_ptr<MathSolution>(new MathSolution()));
	}

	string mathsolution = "item_level_3_solutions.png";

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

	auto man = unique_ptr<Player>(new Player(1000, 1000, lifePoints, 3));
	auto man_ptr = man.get();
	man->view().setSize(sf::Vector2f(game.getScreenResolution().x, game.getScreenResolution().y));
	man->setPosition(sf::Vector2f(500, 500));
	level->setPlayer(move(man));
	man_ptr->setMale(male);

	auto scene = Layer(move(level)).toScene();
	auto timer = unique_ptr<Timer>(new Timer(sf::Vector2f((float)game.getScreenResolution().x - 125, 15), 240));
	auto timer_ptr = timer.get();
	this->setHud(*scene, move(timer), mathsolution);
	scene->setCamera(man_ptr);

	this->game.run(*(scene));
	this->loadPause(*(scene));
	if(man_ptr->getLifePoints() == 0 || timer_ptr->getActualTime() <= 0) {
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

	{
		theseus::scenes::StoryText Storytext(game.getScreenResolution().x, game.getScreenResolution().y, LEVEL4);
		this->game.run(Storytext);
	}

	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 120, Brick::HEIGHT * 50)));
	//set level specific object
	level->addFreeGameObject(unique_ptr<Instrument>(new Instrument()));

	string meter = "item_level_4_meter.png";

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
	man_ptr->setMale(male);

	auto scene = Layer(move(level)).toScene();
	auto timer = unique_ptr<Timer>(new Timer(sf::Vector2f((float)game.getScreenResolution().x - 125, 15), 180));
	auto timer_ptr = timer.get();
	this->setHud(*scene, move(timer), meter);
	scene->setCamera(man_ptr);

	this->game.run(*(scene));
	this->loadPause(*(scene));
	if(man_ptr->getLifePoints() == 0 || timer_ptr->getActualTime() <= 0) {
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

	{
		theseus::scenes::StoryText Storytext(game.getScreenResolution().x, game.getScreenResolution().y, LEVEL5);
		this->game.run(Storytext);
	}

	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 120, Brick::HEIGHT * 50)));
	//set level specific object
	level->addFreeGameObject(unique_ptr<CExam>(new CExam()));

	string cexam = "item_level_5_exam.png";

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
		npc->setExmatriculate();
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
	man_ptr->setMale(male);

	auto scene = Layer(move(level)).toScene();
	auto timer = unique_ptr<Timer>(new Timer(sf::Vector2f((float)game.getScreenResolution().x - 125, 15), 180));
	auto timer_ptr = timer.get();
	this->setHud(*scene, move(timer), cexam);
	scene->setCamera(man_ptr);

	this->game.run(*(scene));
	this->loadPause(*(scene));
	if(man_ptr->getLifePoints() == 0 || timer_ptr->getActualTime() <= 0) {
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

	{
		theseus::scenes::StoryText Storytext(game.getScreenResolution().x, game.getScreenResolution().y, LEVEL6);
		this->game.run(Storytext);
	}


	unique_ptr<LevelDescription> level(new LevelDescription(sf::Vector2f(Brick::WIDTH * 120, Brick::HEIGHT * 50)));
	//set level specific object
	level->addFreeGameObject(unique_ptr<SetlxCup>(new SetlxCup()));

	string setlxcup = "item_level_6_cup.png";

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
		npc->setExmatriculate();
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
	man_ptr->setMale(male);

	auto scene = Layer(move(level)).toScene();
	auto timer = unique_ptr<Timer>(new Timer(sf::Vector2f((float)game.getScreenResolution().x - 125, 15), 180));
	auto timer_ptr = timer.get();
	this->setHud(*scene, move(timer), setlxcup);
	scene->setCamera(man_ptr);

	this->game.run(*(scene));
	this->loadPause(*(scene));
	if(man_ptr->getLifePoints() == 0 || timer_ptr->getActualTime() <= 0) {
		this->playedTime = 0;
		return false;
	}
	else {
		this->lifePoints = man_ptr->getLifePoints();
		this->playedTime += timer_ptr->getActualTime();
		return true;
	}

}

void ScenesManager::setHud(theseus::engine::Scene& scene, std::unique_ptr<theseus::gameobjects::Timer> timer, std::string itemPictureName) {
	auto caffeineLevel = unique_ptr<CaffeineLevel>(new CaffeineLevel(sf::Vector2f((float)game.getScreenResolution().x, 15)));
	scene.addGameObject(move(caffeineLevel));

	auto healthbar = unique_ptr<HealthBar>(new HealthBar(sf::Vector2f(15, 15)));
	scene.addGameObject(move(healthbar));

	scene.addGameObject(move(timer));

	auto itemCounter = unique_ptr<ItemCounter>(new ItemCounter(sf::Vector2f((float)game.getScreenResolution().x - 100, (float)game.getScreenResolution().y - 35), itemPictureName));
	scene.addGameObject(move(itemCounter));
}

void ScenesManager::loadHighScore() {
	theseus::scenes::Highscore highscore(game.getScreenResolution().x, game.getScreenResolution().y, playedTime);
	game.run(highscore);
}
