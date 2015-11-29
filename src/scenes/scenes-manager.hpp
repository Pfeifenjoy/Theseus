/**
 * @author Arwed Mett, Dominic Steinhauser, Philipp Pütz
 */
#ifndef THESEUS_SCENES_SCENES_MANAGER
#define THESEUS_SCENES_SCENES_MANAGER

#include <memory>
#include "../engine/scene.hpp"
#include "../engine/game.hpp"
#include "../gameobjects/player.hpp"
#include "../gameobjects/timer.hpp"
#include "../gameobjects/timer.hpp"
#include "../map/level.hpp"

namespace theseus {
namespace scenes {
	class ScenesManager {
		private:
			theseus::engine::Game game;

			// Global stats
			float playedTime;
			int lifePoints;
			bool male;

		public:
			bool loadStart();
			void loadHighScore();

			void run();

			bool selectCharacter(); // added by Leon Mutschke on 13.11.15

			bool loadLevel1();
			bool loadLevel2();
			bool loadLevel3();
			bool loadLevel4();
			bool loadLevel5();
			bool loadLevel6();

			void loadPause(theseus::map::Level&);
			void setHud(theseus::engine::Scene&, std::unique_ptr<theseus::gameobjects::Timer>, std::string itemPictureName);
	};
}
}
#endif
