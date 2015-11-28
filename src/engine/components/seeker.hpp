/**
 * @autor Arwed Mett
 */
#ifndef THESEUS_ENGINE_COMPONENTS_SEEKER
#define THESEUS_ENGINE_COMPONENTS_SEEKER
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
	class Seeker
		: public virtual theseus::engine::components::Positionable
		, public virtual theseus::engine::components::Solide
   	{
		private:
			/**
			 * A representation of the map.
			 * This describes the fields where the walls are.
			 * It is an abstract representation, that means that it does not contain the exact size of the walls.
			 */
			theseus::map::Map *map;
			/**
			 * Returns all free surrounding fields of a field.
			 * @param {sf::Vector2<int>} position Is the field.
			 * @result {std::pair<int, float>} the free fields and there distance.
			 */
			std::set<std::pair<int, float> > getEdges(int);
			/**
			 * Converts an id of a field into a tuple / vector representation
			 */
			sf::Vector2<int> getPosition_(int position);
			/**
			 * Converts a tuple / vector representation of a field into an id.
			 */
			sf::Vector2<int> getPosition_(sf::Vector2<int>);
			/**
			 * Can be used to circle around a field.
			 * This returns always the next field on a circle around a field.
			 */
			sf::Vector2<int> next(sf::Vector2<int>);
			/**
			 * The field which the seeker has to find.
			 */
			sf::Vector2<int> goal;
			/**
			 * This variable is used to check if the seeker has moved scince the last call of nextDirection.
			 */
			sf::Vector2<int> lastField;
		protected:
			/**
			 * Returns the direction which the seeker has to go if he wants to have the shortest way to his goal.
			 * Returns the 0 vector if the goal has not been found.
			 */
			sf::Vector2<int> nextDirection(sf::Vector2f goal, int radius);
		public:
			/**
			 * Set an abstract map on which the seeker searches.
			 */
			void setMap(theseus::map::Map *map);
	};
}
}
}
#endif

