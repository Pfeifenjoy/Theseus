/**
 * author Arwed Mett
 */
#ifndef THESEUS_MAP_MAP
#define THESEUS_MAP_MAP
#include <vector>
#include <memory>
#include "Layer.hpp"
#include "../engine/scene.hpp"

namespace theseus {
namespace map {
	class Map;
	std::ostream& operator<<(std::ostream&, const Map&);
	class Map {
		private:
			std::vector<std::shared_ptr<Layer> > layers;
		public:
			Map(engine::Scene&);
			friend std::ostream& operator<<(std::ostream&, const Map&);
	};
}
}
#endif
