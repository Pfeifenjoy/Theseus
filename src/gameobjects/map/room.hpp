#ifndef THESEUS_MAP_ROOM
#define THESEUS_MAP_ROOM
#include <vector>
#include <memory>
#include "../../engine/gameobject.hpp"

namespace theseus {
namespace gameobjects {
namespace map {
	class Room {
		private:
			int x;
			int y;
			int width;
			int height;
			std::vector<std::shared_ptr<engine::GameObject> > gameobjects;
		public:
			Room(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
			void addGameObject(std::shared_ptr<engine::GameObject>);

	};
}
}
}
#endif
