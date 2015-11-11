#include "game.hpp"
#include "scene.hpp"
#include "../scenes/menu.hpp"
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <iostream>

using namespace theseus::engine;
using namespace std;

const int DEFAULT_WINDOW_WIDTH = 900;
const int DEFAULT_WINDOW_HEIGTH = 600;
const bool FULLSCREEN = false;

Game::Game()
{

	if (FULLSCREEN)
		window.create(sf::VideoMode().getFullscreenModes()[0], "", sf::Style::Fullscreen);
	else window.create(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGTH), "");
	window.setVerticalSyncEnabled(true);
	window.setMouseCursorVisible(false);
}

bool Game::run(Scene& scene)
{
	// Main loop
	sf::Clock timing;
	sf::Clock fpsClock;
	int fpsCounter = 0;
	int exit = false;
	while (!exit)
	{
		// measure fps
		++fpsCounter;
		if (fpsClock.getElapsedTime().asSeconds() >= 1)
		{
			cout << "FPS: " << fpsCounter << endl;
			fpsCounter = 0;
			fpsClock.restart();
		}


		// process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// window closed?
			if (event.type == sf::Event::Closed) {
				exit = true;
			}

			// handle event
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				scene.handleKeyDownEvent(event.key.code);
				break;
			default:
				// do nothing
				break;
			}
		}
		if(scene.checkFinished()){
			break;
		}

		// update
		float elapsedTime = timing.restart().asSeconds();
		scene.handleUpdateEvent(elapsedTime);

		// render the active scene
		window.clear(sf::Color::Black);
		window.draw(scene);
		window.display();

	}
	return exit;
}

sf::Vector2i Game::getScreenResolution() {
	if (FULLSCREEN)
		return sf::Vector2i(sf::VideoMode().getDesktopMode().width, sf::VideoMode().getDesktopMode().height);
	else
		return sf::Vector2i(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGTH);
}



Game::~Game() {}
