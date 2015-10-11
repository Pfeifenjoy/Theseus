#ifndef _ENGINE_SCENE_H
#define _ENGINE_SCENE_H

// ToDo:
//  - Components
//  - Timers
//  - Collision
//  - Drawing
//  - All the other events

#include <SFML/Graphics.hpp>

namespace theseus
{
namespace engine
{
	class Game;

	class Scene : public sf::Drawable
	{
	private:
		Game* mygame;

	public:
		//---- Constructor -------------------------------------------------------------------------------
		
		Scene(Game& game);
		
		//---- Destructor --------------------------------------------------------------------------------
		
		virtual ~Scene();

		//---- Getters / Setters -------------------------------------------------------------------------

		/**
		 * Returns a reference to the game object that this scene is part of
		 */
		Game& game();

		/**
		 * Returns a const reference to the game object that this scene is part of.
		 */
		const Game& game() const;
		
		//---- Methods -----------------------------------------------------------------------------------
		
	protected:

		/**
		 * Draws the scene to the screen
		 */
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	public:

		//---- Methods.Events
	
		/**
		 * The Game object is supposed to call this function,
		 * when the main window is closed.
		 */
		void handleClosedEvent();

		/**
		 * The Game object is supposed to call this function,
		 * when text is entered.
		 *
		 * For the difference between this event and the
		 * "KeyPressed"- / "KeyReleased"-events, consult the SFML documentation:
		 * http://www.sfml-dev.org/tutorials/2.0/window-events.php#the-textentered-event
		 */
		void handleTextEnteredEvent();

		/**
		 * The Game object is supposed to call this function,
		 * when a key is pressed.
		 */
		void handleKeyPressedEvent();

		/**
		 * The Game object is supposed to call this function,
		 * when a key is released.
		 */
		void handleKeyReleasedEvent();
		
		/**
		 * The Game object is supposed to call this function,
		 * when a mouse button is pressed.
		 */
		void handleMouseButtonPressedEvent();

		/**
		 * The Game object is supposed to call this function,
		 * when a mouse button is released.
		 */
		void handleMouseButtonReleasedEvent();

		/**
		 * The Game object is supposed to call this function,
		 * when the mouse has moved.
		 */
		void handleMouseMovedEvent();
	};
}
}
#endif
