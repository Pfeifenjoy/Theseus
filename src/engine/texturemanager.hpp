/**
 * Autor: Tobias Dorra
 */
#ifndef _THESEUS_ENGINE_TEXTURE_MANAGER_H
#define _THESEUS_ENGINE_TEXTURE_MANAGER_H 

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>

namespace theseus
{
namespace engine
{
	/**
	 * Die Klasse Texturemanager stellt Funktionen zur Verwaltung der Texturen bereit.
	 *
	 * Es können Texturen vom Dateisystem geladen werden und die geladenen Texturen können 
	 * anschließend verwendet werden.
	 *
	 * Die Texturen werden global verwaltet, sodass mehrfach verwendete Texturen tatsächlich
	 * auch nur ein mal geladen werden. Daher ist die Klasse als Singleton implementiert.
	 */
	class TextureManager
	{
	private:

		// The single singleton instance
		static std::unique_ptr<TextureManager>& me();

		// The loaded textures
		std::unordered_map<std::string, std::unique_ptr<sf::Texture> > textures;

		/**
		 * Constructor: Make it private
		 */
		TextureManager();

	public:
	
		/**
		 * Returns the TextureManager instance
		 */
		static TextureManager& instance();

		/**
		 * Deletes the current singleton instance.
		 *
		 * For some unknown reasons, SFML does not like it
		 * if the textures get deleted after the main method
		 * has ended, which would be the case for the 
		 * static singleton implementation used here.
		 *
		 * So, here is a way to reset the singleton instance
		 * manually, while the main function is still running.
		 */
		static void reset();

		/**
		 * Loads a texture from a file.
		 */
		void loadTexture(const std::string& filename);

		/**
		 * Returns a loaded texture.
		 *
		 * Make sure that you have called loadTexture
		 * on the texture you want before using getTexture.
		 *
		 * The reason for why the two methods 
		 * "loadTexture" and "getTexture" are not 
		 * combined into a single one is to encourage the user
		 * of these methods to load the required textures 
		 * on startup and use them later when they are needed.
		 */
		sf::Texture& getTexture(const std::string& filename);
	};
}
}

#endif
