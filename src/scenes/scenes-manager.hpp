/**
 * @author Arwed Mett
 */
#ifndef THESEUS_SCENES_SCENES_MANAGER
#define THESEUS_SCENES_SCENES_MANAGER

#include <memory>
#include "../engine/scene.hpp"
#include "../engine/game.hpp"

namespace theseus {
namespace scenes {
	class ScenesManager {
		private:
			theseus::engine::Game game;
		public:
			//ScenesManager();

			void loadStart();
			//void loadHighScore();

			void run();

			void selectCharacter(); // added by Leon Mutschke on 13.11.15

			void loadLevel1();
			void loadLevel2();
			void loadLevel3();
			void loadLevel4();
			void loadLevel5();
			void loadLevel6();
	};
}
}
#endif
