#ifndef _THESEUS_ENGINE_PUBLISHER_H
#define _THESEUS_ENGINE_PUBLISHER_H

#include <unordered_set>

namespace theseus
{
namespace engine
{
	template <class... T>
	class Subscription;

	/**
	 * An implementation of the Publish-Subscribe pattern.
	 *
	 * This is the publisher-part of the pattern.
	 *
	 * In order to subscribe to the publiched event, you need to create a
	 * matching Subscription object.
	 */
	template <class... T_Arguments>
	class Publisher
	{
	private:
		// the subscriptions
		std::unordered_set<Subscription<T_Arguments...> * > subscriptions;

		// helper functions
		void unsubscribeAll();
		void moveIn(Publisher&& other);
	public:

		//---- Constructors -------------------------------------------------------------------------------------
		
		// Default constructor
		Publisher();

		// Copy constructor (delete it!)
		Publisher(const Publisher& other) = delete;

		// Move constructor
		Publisher(Publisher&& other);

		//---- Destructor ---------------------------------------------------------------------------------------
		
		~Publisher();

		//---- Operators ----------------------------------------------------------------------------------------
	
		// Copy assignment operator (delete it!)
		Publisher& operator=(const Publisher& other) = delete;

		// Move assignment operator
		Publisher& operator=(Publisher&& other);
		
		//---- Subscription handling ----------------------------------------------------------------------------
		
		/**
		 * Adds a subscription to the publisher.
		 */
		void subscribe(Subscription<T_Arguments...>& subscription);

		/**
		 * Removes a subscription from the publisher.
		 */
		void unsubscribe(Subscription<T_Arguments...>& subscription);

	};
}
}

//---- Implementation -------------------------------------------------------------------------------------------------

#include "subscription.hpp"

template <class... T_Arguments>
void theseus::engine::Publisher<T_Arguments...>::unsubscribeAll()
{
	while (!subscriptions.empty())
	{
		unsubscribe(*subscriptions.begin());
	}
}

template <class... T_Arguments>
void theseus::engine::Publisher<T_Arguments...>::moveIn(Publisher<T_Arguments...>&& other)
{
	while (!other.subscriptions.empty())
	{
		auto& subscription = *other.subscriptions.begin();
		other.unsubscribe(subscription);
		subscribe(subscription);
	}
}

template <class... T_Arguments>
theseus::engine::Publisher<T_Arguments...>::Publisher()
{ }

template <class... T_Arguments>
theseus::engine::Publisher<T_Arguments...>::Publisher(Publisher<T_Arguments...>&& other)
{
	moveIn(other);	
}

template <class... T_Arguments>
theseus::engine::Publisher<T_Arguments...>::~Publisher()
{
	unsubscribeAll();
}

template <class... T_Arguments>
theseus::engine::Publisher<T_Arguments...>& theseus::engine::Publisher<T_Arguments...>::operator=(Publisher<T_Arguments...>&& other)
{
	// self assignment check
	if (this == *other)
		return *this;

	// actual move assignment
	unsubscribeAll();
	moveIn(other);
	return *this;
}

template <class... T_Arguments>
void theseus::engine::Publisher<T_Arguments...>::subscribe(Subscription<T_Arguments...>& subscription)
{
	subscriptions.insert(*subscription);
	subscription.publisher = this;
}

template <class... T_Arguments>
void theseus::engine::Publisher<T_Arguments...>::unsubscribe(Subscription<T_Arguments...>& subscription)
{
	subscriptions.erase(*subscription);
	subscription.publisher = nullptr;
}



#endif
