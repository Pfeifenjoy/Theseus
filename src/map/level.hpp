#ifndef THESEUS_MAP_LEVEL
#define THESEUS_MAP_LEVEL
#include "../engine/scene.hpp"
namespace theseus {
namespace map {
	class Level
		: public theseus::engine::Scene
	{
		private:
			sf::Keyboard::Key lastKey;
		public:
			sf::Keyboard::Key getLastKey();
			void handleKeyDownEvent(sf::Keyboard::Key);
	};
}
}

#endif
