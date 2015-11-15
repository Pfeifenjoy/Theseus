/**
*  @Author: Leon Mutschke
*/


#include "hofmann.hpp"
#include "../engine/texturemanager.hpp"

using namespace theseus::gameobjects;
using namespace theseus::engine;


Hofmann::Hofmann()
{
	// texture
	setTexture(2, TextureManager::instance().getTexture("charset_level_4.png"));

	// autotalk
	this->startAutoSpeech({ { "Keiner kommt in den Rosengarten!", "Boah, ist hier ne Luft.", "<b> hi </b>", "Ich bin hier der Boss!" } }, 3, 10, 40, true, true);
}

Hofmann::~Hofmann()
{}

