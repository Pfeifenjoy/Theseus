#include "game.hpp"
#include "scene.hpp"
#include <SFML/Graphics.hpp>
#include <stdexcept>

using namespace theseus::engine;
using namespace std;

const int DEFAULT_WINDOW_WIDTH = 500;
const int DEFAULT_WINDOW_HEIGTH = 500;
const std::string TEXTURES_PATH_PREFIX = "./resources/images/";

Game::Game()
{
	window.create(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGTH), "");
}

void Game::run(unique_ptr<Scene> initialScene)
{
	// Start the scene
	activeScene = std::move(initialScene);
	initialScene = nullptr;
	sceneToLoad = nullptr;

	// Main loop
	bool exit = false;
	while(!exit)
	{
		// start the next scene
		if (sceneToLoad != nullptr)
		{
			inactiveScenes.push(std::move(activeScene));
			activeScene = std::move(sceneToLoad);
			sceneToLoad = nullptr;
		}

		// process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			exit = event.type == sf::Event::Closed;
		}

		// update
		
		// render the active scene
		window.clear(sf::Color::Black);
		window.draw(*activeScene);
		window.display();
		
	}
}

void Game::startScene(std::unique_ptr<Scene> scene)
{
	sceneToLoad = std::move(scene);
}

void Game::loadTexture(const std::string& filename)
{
	// Check if the given texture was already loaded
	if (textures.find(filename) != textures.end())
		return;

	// Try to load the texture
	sf::Texture newTexture;
	if(newTexture.loadFromFile(TEXTURES_PATH_PREFIX + filename))
	{
		textures.insert(std::pair<std::string, sf::Texture>(filename, newTexture));
	}
	else
	{
		throw std::runtime_error("Could not open file.");
	}
}

const sf::Texture& Game::getTexture(const std::string& filename) const
{
	auto iterator = textures.find(filename);

	if (iterator != textures.end())
	{
		return iterator->second;
	}
	else
	{
		throw std::invalid_argument("filename");
	}


}

Game::~Game(){}
