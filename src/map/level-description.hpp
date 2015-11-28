/**
 * @author Arwed Mett
 */
#ifndef THESEUS_LEVEL_DESCRIPTION
#define THESEUS_LEVEL_DESCRIPTION
#include <memory>
#include <vector>
#include "../engine/components/positionable.hpp"
#include "room-description.hpp"
#include "../gameobjects/player.hpp"
#include "../gameobjects/brick.hpp"
#include "../engine/components/seeker.hpp"

namespace theseus {
	namespace map {
		/**
		 * This clas describes a level.
		 * it can be passed to a theseus::map::Layer object
		 * which acts like a generator.
		 * It describes which objects will be generated and placed.
		 */
		class LevelDescription {
		private:
			std::vector<std::unique_ptr<theseus::engine::components::Positionable> > freeObjects;
			std::vector<std::unique_ptr<RoomDescription> > rooms;
			std::unique_ptr<theseus::gameobjects::Player> player;
			sf::Vector2f dimensions;
			sf::Vector2f minRoomSize = sf::Vector2f(theseus::gameobjects::Brick::WIDTH * 7, theseus::gameobjects::Brick::HEIGHT * 7);
			sf::Vector2f maxRoomSize = sf::Vector2f(theseus::gameobjects::Brick::WIDTH * 15, theseus::gameobjects::Brick::HEIGHT * 15);
			int maxAmountOfStandardRooms = 5;
			std::unique_ptr<theseus::engine::components::Seeker> prof;
		public:
			LevelDescription(sf::Vector2f dimensions) : dimensions(dimensions) {}

			//--------------------------------------------------------------------------------//
			// Only relevant for the Generator
			// This are all getters.
			// The generate will generate the Layer -> Scene by the given information.
			//--------------------------------------------------------------------------------//
			sf::Vector2f getDimensions();
			std::vector<std::unique_ptr<theseus::engine::components::Positionable> > getFreeObjects();
			std::vector<std::unique_ptr<RoomDescription> > getRooms();
			std::unique_ptr<theseus::gameobjects::Player> getPlayer();
			sf::Vector2f getMinRoomSize();
			sf::Vector2f getMaxRoomSize();
			int getMaxAmountOfStandardRooms();
			//--------------------------------------------------------------------------------//

			/**
			 * Add GO's which will be placed randomly on the field.
			 * The generator cannot insure that these objects will be placed if the map is to small.
			 */
			void addFreeGameObject(std::unique_ptr<theseus::engine::components::Positionable>);

			/**
			 * Add GO's which will be placed randomly on the field.
			 * The generator cannot insure that these objects will be placed if the map is to small.
			 */
			void addFreeGameObjects(std::vector<std::unique_ptr<theseus::engine::components::Positionable> >);

			/**
			 * Add a special Room to the level.
			 * The generator will try its best to place it on the layer.
			 * Still if there is not enough space it might not be placed.
			 */
			void addRoom(std::unique_ptr<RoomDescription>);

			/**
			 * Add special rooms to the level.
			 * The generator will try its best to place them on the layer.
			 * Still if there is not enough space a room might not be placed.
			 */
			void addRooms(std::vector<std::unique_ptr<RoomDescription> >);

			/**
			 * Specify the minimum width and height of a standard room.
			 */
			void setMinRoomSize(sf::Vector2f);

			/**
			 * Specify the maximum width and height of a standard room.
			 */

			void setMaxRoomSize(sf::Vector2f);

			/**
			 * Set the amount of standard rooms.
			 * These rooms might not be all placed in the level.
			 */
			void setMaxAmountOfStandardRooms(int);

			/**
			 * Set the player to the new level.
			 * This can be used to transfer the status of the player between levels.
			 */
			void setPlayer(std::unique_ptr<theseus::gameobjects::Player>);

			void setProf(std::unique_ptr<theseus::engine::components::Seeker>);

			std::unique_ptr<theseus::engine::components::Seeker> getProf();


		};
	}
}
#endif
