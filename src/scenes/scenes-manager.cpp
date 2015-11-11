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
#include "../map/layer.hpp"

using namespace theseus::scenes;
using namespace theseus::map;
using namespace theseus::gameobjects;
using namespace std;

string const INTRO = "Herzlich Willkommen beim DHBW-Labyrinth-Spiel!\n\n\n"
"ACHTUNG! An der DHBW gibt es aktuell besondere Vorkommnisse...\n"
"Die Dozenten und Professoren sind w�tend und wild geworden! Ein Virus ist aus\n"
"einem Computer ausgebrochen und hat s�mtliche Dozenten und \n"
"Professoren infiziert. Diese haben nun ihre offene, freundliche \n"
"und nette Einstellung gegen�ber den Studenten verloren und versuchen \n"
"nun alle Studenten zu exmatrikulieren. Bring ihnen ihre Gegenst�nde\n"
"und Dokumente zur�ck, um sie zu heilen!"
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
"Best�tigen:	Leertaste";

string const LEVEL1 = "Die erste Herausforderung ist es, Herrn Runge zu heilen.\n"
"Er war immer sehr nett und stellte keine besonders hohen Anspr�che. \n"
"Allerdings findet er gerade die Installations - CD seines Lieblingsprogramms Bizagi nicht.\n"
"Komme ihm nicht zu nahe!Das Virus und seine schlechte Laune f�hren dazu,\n"
"dass er keine Studenten sehen m�chte.Falls er doch einen Studenten sieht, \n "
"versucht er diesen zu exmatrikulieren.\n"
"Also tritt ihm nicht zu nahe!\n"
"Suche die im DHBW - Geb�ude verschwundene Bizagi - Installations - CD und bringe\n"
"sie innerhalb der vorgegeben Zeit Herrn Runge zur�ck,\n"
"der irgendwo innerhalb der DHBW herum irrt.\n"
"1. Suche die CD\n"
"2. Gebe die CD Herrn Runge";

string const LEVEL2 = "Herr Glaser geht �fter w�hrend der Vorlesung die Kreide aus!\n"
"Aus Frust die Vorlesung nicht, wie gewohnt, durchf�hren zu k�nnen, rennt er planlos\n"
"durch die G�nge.Das Virus macht ihn von einem liebevollen Menschen, zu einem Gegner,\n"
"der als Hobby Studenten exmatrikuliert.\n\n"
"Deine Aufgabe ist es, ihn zu heilen!Sammle daf�r in der vorgegebenen Zeit 3 Kreidest�cke\n"
"und bringe sie Herrn Glaser!";

string const LEVEL3 = "Herrn H�bl ist es langweilig...\n\n"
"Das Virus beeinflusst ihn so, dass er keine Studenten mehr sehen m�chte\n"
"und deshalb diese exmatrikuliert.\n"
"Um ihn zu heilen, m�ssen ihm 5 L�sungen zu seinen Mathe-Aufgabenbl�ttern\n"
"�bergeben werden.\n";

string const LEVEL4 = "Puuh ist das wieder eine schlechte Luft hier! Im Geb�ude ist der Sauerstoffgehalt\n"
"ja im negativen Bereich... H�tte Herr Hofmann sein Messger�t, \n"
"w�rde dies nicht passieren. Aber er findet es nicht.\n"
"Ist Herr Hofmann �berhaupt auf der Suche danach?\n"
"Auch er hat das Virus in sich.Trete ihm nicht zu nahe!\n"
"Finde das Messger�t und beruhige / heile Herr Hofmann!\n"
"Pass auf, denn exmatrikulierte Studenten k�nnen Dich jetzt auch attackieren und\n"
"dir wertvolle Zeit zum vollenden des Levels stehlen!";

string const LEVEL5 = "Wo ist die denn die C-Klausur??? Ohne C-Klausur ist f�r Herr Kruse die Welt\n"
"nur halb so sch�n...\n"
"Suche diese und bringe sie Herr Kruse zur�ck!Meide den Kontakt zu deinen Kommilitonen,\n"
"da diese von Virus infiziert sein k�nnten.Falls du mit einem kranken von ihnen\n"
"in Kontakt kommst, wird du langsamer...\n\n"
"Hinweis: Finde eine Apfeltasche und �bergebe diesen Herrn Kruse.Dadurch ist er f�r\n"
"30 Sekunden abgelenkt und exmatrikuliert keinen Studenten.";

string const LEVEL6 = "Herr Stroetmann wurde am schlimmsten von dem Virus befallen...\n\n"
"Hinweis : Suche fructiv zu deiner eigenen Sicherheit!\n\n\n\n\n\n\n\n\n"
"Die Rettung der DHBW ist Nahe...";



void ScenesManager::run()
{
	{	
	theseus::scenes::StoryText Storytext(game.getScreenResolution().x, game.getScreenResolution().y, LEVEL6);
		if (this->game.run(Storytext)) return;
	}
	this->loadStart();
}

void ScenesManager::loadStart() {

	vector<string> buttons;

	buttons.push_back("Start");
	buttons.push_back("Quit");
	Menu menu(buttons, &(this->game));
	this->game.run(menu);

	if (menu.getLastKeyEvent() != sf::Keyboard::Return)
		return;
	switch (menu.getSelectedItemIndex()) {
	case 0: this->loadLevel1(); break;
	case 1: break;
	case 2: break;
	}
}

void ScenesManager::loadLevel1() {
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
	mensa->addGameObject(move(runge));

	level->addRoom(move(mensa));

	auto scene = Layer(move(level)).toScene();

	auto man = unique_ptr<Player>(new Player(100, 100, 3));
	auto man_ptr = man.get();
	man->view().setSize(sf::Vector2f(game.getScreenResolution().x, game.getScreenResolution().y));
	man->setPosition(sf::Vector2f(65, 65));
	scene->addGameObject(move(man));
	scene->setCamera(man_ptr);

	this->game.run(*(scene));
}

void ScenesManager::loadLevel2() {

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
	level->addFreeGameObject(move(glaser));

	auto scene = Layer(move(level)).toScene();
	this->game.run(*(scene));
}
void ScenesManager::loadLevel3() {

}
void ScenesManager::loadLevel4() {

}
void ScenesManager::loadLevel5() {

}
void ScenesManager::loadLevel6() {

}
