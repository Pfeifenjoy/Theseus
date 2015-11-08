/**
 * @autor Arwed Mett
 */
#ifndef THESEUS_MAP_PARKINGAREA
#define THESEUS_MAP_PARKINGAREA
#include "../gameobjects/parking-slot.hpp"
namespace theseus {
namespace map {
	class ParkingArea
   	{
		private:
			std::vector<std::unique_ptr<theseus::gameobjects::ParkingSlot> > slots;
		public:
			ParkingArea(sf::Vector2f, sf::Vector2<int>);
			std::vector<std::unique_ptr<theseus::gameobjects::ParkingSlot> > getSlots();
			~ParkingArea();
	};
}
}
#endif
