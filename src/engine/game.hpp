#ifndef _THESEUS_ENGINE_GAME_H
#define _THESEUS_ENGINE_GAME_H

#include <stack>
#include <SFML/Graphics.hpp>

namespace engine
{
	class Scene;

	class Window
	{
	private:
		// The window which is drawn to
		sf::RenderWindow window;

		// The stack of loaded scenes.
		std::stack<Scene> scenes;
	public:

		//---- Constructors --------------------------------------------------------------
		
		/**
		 * Default constructor
		 */
		Window();

		//---- Methods -------------------------------------------------------------------
		
		/**
		 * Runs the main loop with the given Scene as the initial scene.
		 */
		void run(const Scene& InitialScene);

		/**
		 * Displays the given scene and lets the player 
		 * interact with it.
		 * The current scene will be paused until the started scene
		 * is stopped.
		 */
		void startScene(Scene& scene);



	};
};

#endif
