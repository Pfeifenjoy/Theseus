#include "texturemanager.hpp"

using namespace std;
using namespace theseus::engine;

const std::string TEXTURES_PATH_PREFIX = "./resources/images/";

std::unique_ptr<TextureManager>& TextureManager::me()
{
	static unique_ptr<TextureManager> mePtr = nullptr;
	return mePtr;
}

TextureManager::TextureManager()
{}

TextureManager& TextureManager::instance()
{
	if (me() == nullptr)
		me() = unique_ptr<TextureManager>(new TextureManager);
	return *me();
}

void TextureManager::reset()
{
	me().release();
}

void TextureManager::loadTexture(const string& filename)
{
	// Check if the given texture was already loaded
	if (textures.find(filename) != textures.end())
		return;

	// Try to load the texture
 	unique_ptr<sf::Texture> newTexture(new sf::Texture());
	if(newTexture->loadFromFile(TEXTURES_PATH_PREFIX + filename))
	{
		textures.insert(make_pair(filename, move(newTexture)));
	}
	else
	{
		throw std::runtime_error("Could not open file: " + TEXTURES_PATH_PREFIX + filename);
	}
}

sf::Texture& TextureManager::getTexture(const string& filename)
{
	auto iterator = textures.find(filename);

	if (iterator != textures.end())
	{
		return *iterator->second;
	}
	else
	{
		throw std::invalid_argument("filename - Have you loaded all required textures using TextureManager::instance().loadTexture('texture.png')?");
	}
}
