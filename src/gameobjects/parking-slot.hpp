/**
 * @author Arwed Mett
 */
#ifndef THESEUS_GAMEOBJECTS_PARKING_SLOT
#define THESEUS_GAMEOBJECTS_PARKING_SLOT
#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
namespace theseus {
namespace gameobjects {
	class ParkingSlot
		: public theseus::engine::GameObject
		, public virtual theseus::engine::components::Sprite
   	{
		public:
			ParkingSlot(int, int width, int height);
			enum {LEFT, RIGHT};
			~ParkingSlot();
	};
}
}
#endif
