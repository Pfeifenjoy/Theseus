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

		// The stack of loaded scenes.
		std::stack<std::unique_ptr<Scene> > inactiveScenes;
		std::unique_ptr<Scene> activeScene = nullptr;
		std::unique_ptr<Scene> sceneToLoad = nullptr;

		// The loaded textures
		std::unordered_map<std::string, std::unique_ptr<sf::Texture> > textures;

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
		 *
		 * !!! Caution !!! only call this function once, in the 
		 * main function of your application. 
		 * If you want to change the active scene during the running
		 * game, you can use the startScene() method.
		 */
		void run(std::unique_ptr<Scene> initialScene);

		/**
		 * Displays the given scene and lets the player 
		 * interact with it.
		 * The current scene will be paused until the started scene
		 * is stopped.
		 */
		void startScene(std::unique_ptr<Scene> scene);

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
