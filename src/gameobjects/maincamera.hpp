#ifndef _THESEUS_GAME_OBJECTS_MAIN_CAMERA_H
#define _THESEUS_GAME_OBJECTS_MAIN_CAMERA_H value

#include "../engine/components/camera.hpp"
#include "../engine/components/speed.hpp"
#include "../engine/gameobject.hpp"

namespace theseus
{
namespace gameobjects
{

class MainCamera : public engine::GameObject
		 , public virtual engine::components::Camera
		 , public virtual engine::components::Speed
{
	private:

	public:
		MainCamera();
		virtual ~MainCamera();
};

}
}

#endif
