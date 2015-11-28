/**
 * Autor: Tobias Dorra
 */
#ifndef _THESEUS_ENGINE_PUBLISHER_H
#define _THESEUS_ENGINE_PUBLISHER_H

#include <vector>
#include <functional>

namespace theseus
{
namespace engine
{
	/**
	 * An implementation of the Publish-Subscribe pattern.
	 */
	template <class... T_Arguments>
	class Publisher
	{
	private:
		// the subscriptions
		std::vector<std::function<void(T_Arguments...)> > subscriptions;

	public:

		//---- Constructors -------------------------------------------------------------------------------------
		
		// Default constructor
		Publisher();

		// Delete the copy & move constructor
		Publisher(const Publisher& other) = delete;
		Publisher(Publisher&& other) = delete;

		//---- Operators ----------------------------------------------------------------------------------------
	
		// Copy & Move assignment operator (delete it!)
		Publisher& operator=(const Publisher& other) = delete;
		Publisher& operator=(Publisher&& other) = delete;

		// Function call operator
		void operator()(T_Arguments...) const;
		
		//---- Subscription handling ----------------------------------------------------------------------------
		
		/**
		 * Adds a subscription to the publisher.
		 */
		void subscribe(const std::function<void(T_Arguments...)>& fn);

	};
}
}

//---- Implementation -------------------------------------------------------------------------------------------------

template <class... T_Arguments>
theseus::engine::Publisher<T_Arguments...>::Publisher()
{ }

template <class... T_Arguments>
void theseus::engine::Publisher<T_Arguments...>::subscribe(const std::function<void(T_Arguments...)>& subscription)
{
	subscriptions.push_back(subscription);
}

template <class... T_Arguments>
void theseus::engine::Publisher<T_Arguments...>::operator()(T_Arguments... arguments) const
{
	for(auto& subscription : subscriptions)
	{
		subscription(arguments...);
	}
}

#endif
