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
		void setCallback(const std::function<void(T_Arguments...)>& callback);
		
		/**
		 * Sets the callback to a non-const member function of an object.
		 *
		 * CAUTION: you need to update the callback to point to the method in the
		 * new object, when the object gets copyed or moved.
		 */
		template <class T_This>
		void setCallback(const std::function<void(T_This*, T_Arguments...)>&, T_This* thisValue);

		/**
		 * Sets the callback to a const member function of an object.
		 *
		 * CAUTION: you need to update the callback to point to the method in the
		 * new object, when the object gets copyed or moved.
		 */
		template <class T_This>
		void setCallback(const std::function<void(const T_This*, T_Arguments...)>&, const T_This* thisValue);
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

template <class... T_Arguments>
void theseus::engine::Subscription<T_Arguments...>::setCallback(const std::function<void(T_Arguments...)>& fn)
{
	this->callback = fn;
}

template <class... T_Arguments>
template <class T_This>
void theseus::engine::Subscription<T_Arguments...>::setCallback(const std::function<void(T_This*, T_Arguments...)>& fn, T_This* thisValue)
{
	this->callback = [=](T_Arguments... args){fn(thisValue, args...);};
}

template <class... T_Arguments>
template <class T_This>
void theseus::engine::Subscription<T_Arguments...>::setCallback(const std::function<void(const T_This*, T_Arguments...)>& fn, const T_This* thisValue)
{
	this->callback = [=](T_Arguments... args){fn(thisValue, args...);}; 
}

#endif
