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
		public:
			std::vector<std::vector<int> > map;
			Map(std::vector<std::vector<theseus::map::FieldStatus> >& layer);
	};
}
}
#endif
