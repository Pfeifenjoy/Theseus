#ifndef THESEUS_MAP_MAP
#define THESEUS_MAP_MAP
#include <vector>
#include "field-status.hpp"
#include <SFML/Graphics.hpp>
#include "../engine/gameobject.hpp"


namespace theseus {
namespace map {
	class Map
	: public theseus::engine::GameObject
	{
		private:
			sf::Vector2<int> goal;
		public:
			std::vector<std::vector<bool> > map;
			Map(std::vector<std::vector<theseus::map::FieldStatus> >& layer);
			void updatePlayerPosition(sf::Vector2f);
			sf::Vector2<int> getGoal();
			sf::Vector2<int> getPathToPlayer(sf::Vector2f startPosition, int radius);

	};
}
}
#endif
