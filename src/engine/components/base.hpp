#ifndef _THESEUS_ENGINE_COMPONENTS_BASE_H
#define _THESEUS_ENGINE_COMPONENTS_BASE_H

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
		Scene* myscene;
	public:
		//---- Getters / Setters ----------------------------------------------------------------------------------
		
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
