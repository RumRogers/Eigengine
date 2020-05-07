#include "Subject.h"
#include "IObserver.h"
#include <algorithm>

namespace EigenCore
{
	// I would normally pass the first parameter as const IObserver* const...
	// Unfortunately, the C++ Standard forbids containers of const elements because allocator<const T>
	// is ill-formed (Error C2338) 
	void Subject::attach(IObserver* const subscriber, const Event::EventType evType)
	{
		auto it = m_subscribers.find(evType);

		if (!keyExists(evType))
		{
			m_subscribers.emplace(evType, std::vector<IObserver*> { subscriber });
		}

		else
		{
			// assert isSubscribed(subscriber, evType) == false
			m_subscribers.at(evType).emplace_back(subscriber);
		}
	}

	void Subject::detach(IObserver* const subscriber, const Event::EventType evType)
	{
		// assert keyExists(evType) && isSubscribed(subscriber, evType) == true
		auto& subscribersList = m_subscribers.at(evType);

		subscribersList.erase(std::find(subscribersList.begin(), subscribersList.end(), subscriber));
	}

	void Subject::notify(const GameObject* sender, const Event* ev) const
	{
		auto& subscribersList = m_subscribers.at(ev->type);
		for (auto subscriber : subscribersList)
		{
			subscriber->handleEvent(sender, ev);
		}

	}

	bool Subject::keyExists(const Event::EventType evType) const
	{
		auto it = m_subscribers.find(evType);

		return it != m_subscribers.end();
	}

	bool Subject::isSubscribed(const IObserver* const subscriber, const Event::EventType evType) const
	{
		auto subscribersList = m_subscribers.at(evType);
		auto it_subscribers = std::find(subscribersList.begin(), subscribersList.end(), subscriber);

		return it_subscribers != subscribersList.end();
	}
}