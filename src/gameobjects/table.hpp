/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_TABLE_H
#define _THESEUS_GAME_OBJECTS_TABLE_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include "../engine/components/solide.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class Table
			: public engine::GameObject
			, public virtual engine::components::Sprite
			, public virtual theseus::engine::components::Solide
		{
		private:
			int tableType;


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Table(sf::Vector2f position, int tableType);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Table();

			void setType(int tableType);
			
		};
	}
}

#endif

