/**
 * @author Arwed Mett
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
			float playedTime;
			int lifePoints = 3;
			bool male;

		public:
			//ScenesManager();

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
			bool startLevel();
			void loadPause(theseus::map::Level&);
			bool evaluateLevel(theseus::gameobjects::Player&, theseus::gameobjects::Timer&);
			void setHud(theseus::engine::Scene&, std::unique_ptr<theseus::gameobjects::Timer>, std::string itemPictureName);
	};
}
}
#endif
