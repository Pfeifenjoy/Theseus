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
const bool FULLSCREEN = true;

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

	window.setMouseCursorVisible(false);

	// Main loop
	sf::Clock timing;
	sf::Clock fpsClock;
	int fpsCounter = 0;
	exit = false;
	menuIsOpen = false;
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
			if (event.type == sf::Event::Closed) {
				exit = true;
			}

			// handle event
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape && !menuIsOpen) {
					menuIsOpen = true;
					vector<std::string >  menuItems;
					menuItems.push_back("Spiel fortsetzen");
					menuItems.push_back("Spiel beenden");

					vector<unique_ptr<Scene> > scenes;
					scenes.push_back(move(activeScene));
					scenes.push_back(nullptr);

					unique_ptr<Menu> menuScene = unique_ptr<Menu>(new Menu(menuItems, scenes, this));
					activeScene = std::move(menuScene);
					activeScene->handleSceneStartedEvent();
				}
				else {
					activeScene->handleKeyDownEvent(event.key.code);
				}				
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
	menuIsOpen = false;
	sceneToLoad = std::move(scene);
}

void Game::quitGame()
{
	exit = true;
}


Game::~Game() {}
