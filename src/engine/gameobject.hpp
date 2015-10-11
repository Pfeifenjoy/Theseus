#ifndef _THESEUS_ENGINE_GAME_OBJECT_H
#define _THESEUS_ENGINE_GAME_OBJECT_H

namespace theseus
{
namespace engine
{
	class Scene;
	
	class Game;

	class GameObject
	{
	private:
		Scene* myscene;
	public:
		//---- Constructors ---------------------------------------------------------------------------------------
		
		GameObject(Scene& scene);
	
		//---- Destructor -----------------------------------------------------------------------------------------
		
		virtual ~GameObject();

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
#endif
