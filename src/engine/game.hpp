/**
 * @autor Tobias Dorra, Arwed Mett
 */
#ifndef _THESEUS_ENGINE_GAME_H
#define _THESEUS_ENGINE_GAME_H

#include <stack>
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <memory>

namespace theseus
{
namespace engine
{
	class Scene;

	class Game
	{
	private:
		// The window which is drawn to
		sf::RenderWindow window;

		bool exit;


	public:

		//---- Constructors --------------------------------------------------------------

		/**
		 * Default constructor
		 */
		Game();

		//---- Destructor ----------------------------------------------------------------

		~Game();

		//---- Methods -------------------------------------------------------------------

		//---- Methods.Scene management

		/**
		 * Runs the main loop with the given Scene as the initial scene.
		 */
		bool run(Scene& initialScene);

		// Returns the resolution of the screen
		sf::Vector2i getScreenResolution();

	};
}
}

#endif
