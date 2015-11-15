/**
*  @Author: Leon Mutschke
*/


#include "glaser.hpp"
#include "../engine/texturemanager.hpp"

using namespace theseus::gameobjects;
using namespace theseus::engine;


Glaser::Glaser()
{
	// texture
	setTexture(2, TextureManager::instance().getTexture("charset_level_2.png"));

	// autotalk
	this->startAutoSpeech({ { "0110100001101001", "Schon wieder keine Kreide.", "AND oder NAND?", "XOR, NOR oder OR?" } }, 3, 10, 40, true, true);
}

Glaser::~Glaser()
{}

