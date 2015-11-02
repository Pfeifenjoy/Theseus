/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_UML_DIAGRAMM_H
#define _THESEUS_GAME_OBJECTS_UML_DIAGRAMM_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class UMLDiagramm
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			UMLDiagramm(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~UMLDiagramm();
		};
	}
}

#endif
#pragma once
