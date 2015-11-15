/**
 * @autor Arwed Mett
 */
#ifndef THESEUS_ENGINE_COMPONENTS_SEAKER
#define THESEUS_ENGINE_COMPONENTS_SEAKER
#include "../../map/map.hpp"
#include <SFML/Graphics.hpp>
#include "../gameobject.hpp"
#include "positionable.hpp"
#include <set>
#include <utility>
#include <SFML/Graphics.hpp>
#include "solide.hpp"

namespace theseus {
namespace engine {
namespace components {
	class Seaker
		: public virtual theseus::engine::components::Positionable
		, public virtual theseus::engine::components::Solide
   	{
		private:
			std::vector<std::pair<int, int> > graph;
			theseus::map::Map *map;
			std::vector<std::pair<sf::Vector2<int>, sf::Vector2<int> > > getEdges(sf::Vector2<int> position, int radius);
			std::set<std::pair<int, float> > getEdges(int);
			std::vector<int> constructPath(int source, int goal, std::map<int, int> backEdge);
			sf::Vector2<int> getPosition_(int position);
			sf::Vector2<int> getPosition_(sf::Vector2<int>);
			sf::Vector2<int> next(sf::Vector2<int>);
			sf::Vector2<int> goal;
			bool inBrick = false;
			sf::Vector2<int> lastField;
		protected:
			sf::Vector2<int> nextDirection(sf::Vector2f goal, int radius);
		public:
			void setMap(theseus::map::Map *map);
	};
}
}
}
#endif

