/**
 * @author Arwed Mett
 */
#ifndef THESEUS_MAP_MAP
#define THESEUS_MAP_MAP
#include <vector>
#include <memory>
#include "layer.hpp"
#include "../engine/scene.hpp"
#include "../engine/components/update.hpp"
#include "../engine/components/drawable.hpp"

namespace theseus {
namespace map {
	class Map;
	std::ostream& operator<<(std::ostream&, const Map&);
	class Map
		: public engine::GameObject
		, public virtual engine::components::Drawable
	{
		private:
			//Events
			void onUpdate(float passedTime);

			std::vector<std::shared_ptr<Layer> > layers;
		public:
			Map(engine::Scene&);
			friend std::ostream& operator<<(std::ostream&, const Map&);
	};
}
}
#endif
