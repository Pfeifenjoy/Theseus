/**
*  @Author: Leon Mutschke
*/


#include "runge.hpp"
#include "../engine/texturemanager.hpp"

using namespace theseus::gameobjects;
using namespace theseus::engine;

Runge::Runge()
{
	// texture
	setTexture(2, TextureManager::instance().getTexture("charset_level_1.png"));

	// autotalk
	this->startAutoSpeech({ { "Wo ist meine CD?", "Komm her, ich tu dir nichts!", "Komm her, ich schmeiss dich raus!", "Hm?" } }, 3, 10, 40, true, true);
}

Runge::~Runge()
{}

