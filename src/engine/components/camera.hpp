/**
 * Autor: Tobias Dorra
 */
#ifndef _THESEUS_ENGINE_COMPONENTS_CAMERA
#define _THESEUS_ENGINE_COMPONENTS_CAMERA 

#include <SFML/Graphics.hpp>
#include "position.hpp"

namespace theseus
{
namespace engine
{
namespace components
{

/**
 * This component defines a rectangle that is used to set the field of view in the rendering process.
 * In order to use a camera, the setCamera method of the scene has to be called.
 */
class Camera : public virtual Position
{
	private:
		// the view that is used to render the scene.
		sf::View m_view;

	public:

		/**
		 * Returns a reference(!) to the view used for rendering, if the camera is active.
		 * (const and non-const versions)
		 */
		sf::View& view();
		const sf::View& view() const;

		/**
		 * Destructor, virtual.
		 */
		virtual ~Camera();
};

}
}
}

#endif
