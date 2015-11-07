/**
 * @autor Arwed Mett
 */
#ifndef THESEUS_GAMEOBJECTS_PARKINGAREA
#define THESEUS_GAMEOBJECTS_PARKINGAREA
#include "parking-slot.hpp"
namespace theseus {
namespace gameobjects {
	class ParkingArea
   	{
		private:
			std::vector<std::unique_ptr<ParkingSlot> > slots;
		public:
			ParkingArea(sf::Vector2f, sf::Vector2<int>);
			std::vector<std::unique_ptr<ParkingSlot> > getSlots();
			~ParkingArea();
	};
}
}
#endif
