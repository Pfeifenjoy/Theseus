/**
 * @author Arwed Mett, Tobias Dorra, Dominic Steinhauser, Philipp Pütz, Leon Mutschke
 */
#include "engine/end-of-Time.hpp"
#include "engine/texturemanager.hpp"
#include "scenes/scenes-manager.hpp"

#include <memory>

using namespace std;
using namespace theseus::engine;
using namespace theseus::gameobjects;
using namespace theseus::map;

int main()
{
	// init random number generator
	srand((unsigned)time(NULL));

	// load the textures
	TextureManager::instance().loadTexture("parking_area.png");
	TextureManager::instance().loadTexture("parking_area_double.png");
	TextureManager::instance().loadTexture("player.png");
	TextureManager::instance().loadTexture("player_fem.png");
	TextureManager::instance().loadTexture("player2.png");
	TextureManager::instance().loadTexture("player2_infected.png");
	TextureManager::instance().loadTexture("bar.png");
	//texture professor ------------------------------------------------------------
	TextureManager::instance().loadTexture("charset_level_1.png");
	TextureManager::instance().loadTexture("charset_level_2.png");
	TextureManager::instance().loadTexture("charset_level_3.png");
	TextureManager::instance().loadTexture("charset_level_4.png");
	TextureManager::instance().loadTexture("charset_level_5.png");
	TextureManager::instance().loadTexture("charset_level_6.png");
	//-------------------------------------------------------------------------------
	TextureManager::instance().loadTexture("wall_horizontal.png");
	TextureManager::instance().loadTexture("wall_vertical.png");
	TextureManager::instance().loadTexture("wall_edge_left_bottom.png");
	TextureManager::instance().loadTexture("wall_edge_left_top.png");
	TextureManager::instance().loadTexture("wall_edge_right_bottom.png");
	TextureManager::instance().loadTexture("wall_edge_right_top.png");
	TextureManager::instance().loadTexture("wall_left_middle.png");
	TextureManager::instance().loadTexture("wall_left_end.png");
	TextureManager::instance().loadTexture("wall_right_middle.png");
	TextureManager::instance().loadTexture("wall_right_end.png");
	TextureManager::instance().loadTexture("wall_bottom_end.png");
	TextureManager::instance().loadTexture("wall_top_end.png");
	TextureManager::instance().loadTexture("wall_cross.png");
	TextureManager::instance().loadTexture("wall_T_cross.png");
	TextureManager::instance().loadTexture("wall_T_upsidedown_cross.png");
	TextureManager::instance().loadTexture("floor_black.png");
	TextureManager::instance().loadTexture("floor_red.png");
	TextureManager::instance().loadTexture("gras.png");
	TextureManager::instance().loadTexture("item_level_3_solutions.png");
	TextureManager::instance().loadTexture("item_level_4_meter.png");
	TextureManager::instance().loadTexture("item_coffee.png");
	TextureManager::instance().loadTexture("item_level_2_chalk.png");
	TextureManager::instance().loadTexture("item_level_5_exam.png");
	TextureManager::instance().loadTexture("item_level_5_appleturnover.png");
	TextureManager::instance().loadTexture("item_level_6_cup.png");
	TextureManager::instance().loadTexture("item_level_1_bizagi_cd.png");
	TextureManager::instance().loadTexture("heart.png");
	TextureManager::instance().loadTexture("speech_bubble.png");

	theseus::scenes::ScenesManager game;
	try {
		game.run();
	} catch (const theseus::engine::EndOfTime &e) {
	}
	TextureManager::reset();
	return 0;
}
