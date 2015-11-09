/**
 * @autor Arwed Mett
 */
#ifndef THESEUS_MAP_PARKINGAREA
#define THESEUS_MAP_PARKINGAREA
#include "../gameobjects/parking-slot.hpp"
namespace theseus {
namespace map {
	/**
	 * This is a helper class which generates parking slots, which will be placed in a bigger area.
	 */
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
