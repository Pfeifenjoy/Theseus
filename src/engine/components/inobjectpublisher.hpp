#ifndef _THESEUS_ENGINE_COMPONENTS_IN_OBJECT_PUBLISHER_H
#define _THESEUS_ENGINE_COMPONENTS_IN_OBJECT_PUBLISHER_H

#include <functional>
#include <vector>

namespace theseus
{
namespace engine
{
namespace components
{

	template <class T_Publisher, class... T_Args>
	class InObjectPublisher
	{
	private:
		std::vector<std::function<void(T_Args...)> > subscribers;

	public:

		//---- Constructors ------------------------------------------------------------------------------
		
		/**
		 * Default constructor
		 */
		InObjectPublisher();

	protected:

		//---- Methods -----------------------------------------------------------------------------------
		
		/**
		 * Adds a member function to the subscribers
		 */
		void subscribe(const std::function<void(T_Args...)>& fn);

		/**
		 * Calls all subscribed functions
		 */
		void call(T_Args...);

		//---- Operators ---------------------------------------------------------------------------------
		
		/**
		 * Calls all subscribed functions
		 */
		void operator()(T_Args...);
	};

}
}
}

#endif
