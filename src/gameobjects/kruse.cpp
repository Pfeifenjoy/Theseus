/**
*  @Author: Leon Mutschke
*/

#include "kruse.hpp"
#include "../engine/texturemanager.hpp"

using namespace theseus::gameobjects;
using namespace theseus::engine;

Kruse::Kruse()
{
	// texture
	setTexture(2, TextureManager::instance().getTexture("charset_level_5.png"));

	// autotalk
	this->startAutoSpeech({ { "while(1){ printf(\"C is great!\");}", "Apfeltasche? Lecker...", "Daumengeste?", "Mein Gluecksrad ist toll!" } }, 3, 10, 40, true, true);
}

Kruse::~Kruse()
{}

