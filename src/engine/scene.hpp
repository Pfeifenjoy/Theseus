#ifndef _ENGINE_SCENE_H
#define _ENGINE_SCENE_H

namespace engine
{
	class Scene
	{
	private:
	public:
		//---- Constructor -------------------------------------------------------------------------------
		
		Scene();

		//---- Destructor --------------------------------------------------------------------------------
		
		virtual ~Scene(){};

		//---- Methods -----------------------------------------------------------------------------------
		
		//---- Methods.Events ----------------------------------------------------------------------------
	
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

#endif
