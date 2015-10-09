#ifndef _THESEUS_ENGINE_GAME_H
#define _THESEUS_ENGINE_GAME_H

#include <stack>
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

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

		// The stack of loaded scenes.
		std::stack<Scene> scenes;

		// The loaded textures
		std::map<std::string, sf::Texture> textures;

	public:

		//---- Constructors --------------------------------------------------------------
		
		/**
		 * Default constructor
		 */
		Game();

		//---- Methods -------------------------------------------------------------------
	
		//---- Methods.Scene management

		/**
		 * Runs the main loop with the given Scene as the initial scene.
		 */
		void run(const Scene& initialScene);

		/**
		 * Displays the given scene and lets the player 
		 * interact with it.
		 * The current scene will be paused until the started scene
		 * is stopped.
		 */
		void startScene(const Scene& scene);

		//---- Methods.TextureManagement
		
		/**
		 * Loads the texture from the given filename into the
		 * graphics card memory
		 */
		void loadTexture(const std::string& filename);

		/**
		 * Returns a reference to the texture that was loaded
		 * before using the given filename.
		 */
		const sf::Texture& getTexture(const std::string& filename) const;

	};
}
}

#endif
