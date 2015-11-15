/**
*  @Author: Leon Mutschke
*/

#include "huebl.hpp"
#include "../engine/texturemanager.hpp"

using namespace theseus::gameobjects;
using namespace theseus::engine;


Huebl::Huebl()
{
	// texture
	setTexture(2, TextureManager::instance().getTexture("charset_level_3.png"));

	// autotalk
	this->startAutoSpeech({ { "Uebungsblaetter...", "Griechische Buchstaben sind cool!", "Alpha, Beta, Gamma, ...?", "Mathematik, Mathematik" } }, 3, 10, 40, true, true);

}

Huebl::~Huebl()
{}

