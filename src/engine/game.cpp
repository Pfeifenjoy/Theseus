#include "game.hpp"
#include "scene.hpp"
#include <SFML/Graphics.hpp>
#include <stdexcept>

using namespace theseus::engine;

const int DEFAULT_WINDOW_WIDTH = 500;
const int DEFAULT_WINDOW_HEIGTH = 500;
const std::string TEXTURES_PATH_PREFIX = "./resources/images/";

Game::Game()
{
	window.create(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGTH), "");
}

void Game::run(const Scene& initialScene)
{
	// Start the scene
	startScene(initialScene);

	// Main loop
	while(true)
	{
		// process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return;
		}

		// update
		// render
	}
}

void Game::startScene(const Scene& scene)
{
	scenes.push(scene);
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
