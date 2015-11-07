#include "game.hpp"
#include "scene.hpp"
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
}

void Game::run(unique_ptr<Scene> initialScene)
{
	// Start the scene
	activeScene = std::move(initialScene);
	initialScene = nullptr;
	sceneToLoad = nullptr;
	activeScene->handleSceneStartedEvent();

	// Main loop
	sf::Clock timing;
	sf::Clock fpsClock;
	int fpsCounter = 0;
	bool exit = false;
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
		// start the next scene
		if (sceneToLoad != nullptr)
		{
			inactiveScenes.push(std::move(activeScene));
			activeScene = std::move(sceneToLoad);
			sceneToLoad = nullptr;
			activeScene->handleSceneStartedEvent();
		}

		// process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// window closed?
			exit = event.type == sf::Event::Closed;

			// handle event
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				activeScene->handleKeyDownEvent(event.key.code);
				break;
			default:
				// do nothing
				break;
			}
		}

		// update
		float elapsedTime = timing.restart().asSeconds();
		activeScene->handleUpdateEvent(elapsedTime);

		// render the active scene
		window.clear(sf::Color::Black);
		window.draw(*activeScene);
		window.display();

	}
}

sf::Vector2i Game::getScreenResolution() {
	if (FULLSCREEN)
		return sf::Vector2i(sf::VideoMode().getDesktopMode().width, sf::VideoMode().getDesktopMode().height);
	else
		return sf::Vector2i(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGTH);
}

void Game::startScene(std::unique_ptr<Scene> scene)
{
	sceneToLoad = std::move(scene);
}


Game::~Game() {}
