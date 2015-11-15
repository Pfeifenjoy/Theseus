/**
*  @Author: Leon Mutschke
*/

#include "stroetmann.hpp"
#include "../engine/texturemanager.hpp"

using namespace theseus::gameobjects;
using namespace theseus::engine;

Stroetmann::Stroetmann()
{
	// texture
	setTexture(2, TextureManager::instance().getTexture("charset_level_6.png"));

	// autotalk
	this->startAutoSpeech({ { "IF AND ONLY IF", "SetlX ist toll!", "Go away iff you hate formal logic.", "Merge Sort beats Quick Sort.", "Was sind zwei Lemmas? - Ein Dilemma" } }, 3, 10, 40, true, true);

}

Stroetmann::~Stroetmann()
{}

