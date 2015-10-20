#ifndef _THESEUS_ENGINE_COMPONENTS_BASE_H
#define _THESEUS_ENGINE_COMPONENTS_BASE_H

#include "../publisher.hpp"

namespace theseus
{
namespace engine
{

class GameObject;
class Scene;
class Game;

namespace components
{
	class Base
	{
	friend class theseus::engine::GameObject;
	private:
		Scene* myscene = nullptr;
	protected:

		Publisher<> evBaseInitialized;

		/**
		 * Returns wether the pointer to the scene has already been initialized.
		 * It is only save to use the getters/setters of this component if 
		 * the pointer has been initialized.
		 */
		bool isInitialized() const;
		
		//---- Getters / Setters ----------------------------------------------------------------------------------

	public:
		/**
		 * Returns a reference to the scene that manages this game object.
		 */
		Scene& scene();

		/**
		 * Returns a const reference to the scene that manages this game object.
		 */
		const Scene& scene() const;

		/**
		 * Returns a reference to the game that this game object is part of.
		 *
		 * Note that this method is just a shortcut for scene().game() 
		 */
		Game& game();

		/**
		 * Returns a const reference to the game that this game object is part of.
		 *
		 * Note that this method is just a shortcut for scene().game() 
		 */
		const Game& game() const;
	};
}
}
}
#endif
