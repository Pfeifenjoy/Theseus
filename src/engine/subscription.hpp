#ifndef _THESEUS_ENGINE_SUBSCRIPTION_H
#define _THESEUS_ENGINE_SUBSCRIPTION_H

#include <functional>

namespace theseus
{
namespace engine
{

	template <class... T>
	class Publisher;

	template <class... T_Arguments>
	class Subscription
	{
		friend class Publisher<T_Arguments...>;
	private:
		Publisher<T_Arguments...>* publisher = nullptr;
		std::function<void(T_Arguments...)> callback;
	public:
		//---- Constructors -----------------------------------------------------------------------------------
		
		/**
		 * Default constructor
		 */
		Subscription();

		/**
		 * Copy assignment operator
		 */
		Subscription(const Subscription& other);

		//---- Destructor -------------------------------------------------------------------------------------
		
		~Subscription();

		//---- Operators -------------------------------------------------------------------------------------- 
	
		/**
		 * Copy assignment operator
		 */
		Subscription& operator=(const Subscription& other);

		//---- Getters / Setters ------------------------------------------------------------------------------
	
		/**
		 * Sets the callback that is used when the publisher emits an event.
		 */
		void setCallback(std::function<void(T_Arguments...)> callback);
	};

}
}

//---- implementation -------------------------------------------------------------------------------------------------

#include "publisher.hpp"

template <class... T_Arguments>
theseus::engine::Subscription<T_Arguments...>::Subscription()
{}

template <class... T_Arguments>
theseus::engine::Subscription<T_Arguments...>::Subscription(const theseus::engine::Subscription<T_Arguments...>& other)
{
	callback = other.callback;
	if (other.publisher != nullptr)
		other.publisher->subscribe(*this);
}

template <class... T_Arguments>
theseus::engine::Subscription<T_Arguments...>::~Subscription()
{
	if (publisher != nullptr)
		publisher->unsubscribe(*this);
}

template <class... T_Arguments>
theseus::engine::Subscription<T_Arguments...>& theseus::engine::Subscription<T_Arguments...>::operator=(const theseus::engine::Subscription<T_Arguments...>& other)
{
	// self-assignment check
	if (this == &other)
		return *this;

	// actual assignment
	callback = other.callback;
	if (other.publisher != nullptr)
		other.publisher->subscribe(*this);
}


#endif
