#pragma once

#include <unordered_map>
#include <vector>
#include "Event.h"

namespace EigenCore
{
	class IObserver;
	class GameObject;

	// Observer pattern, I don't need the Subject class to be abstract
	class Subject
	{
	public:
		virtual ~Subject() {}
		// The GameObject requires to be notified when a specific event type occurs by calling the callback.
		void attach(IObserver* const subscriber,  const Event::EventType);
		// The GameObject opts out of notifications for a specific event type
		void detach(IObserver* const subscriber, const Event::EventType);
		// Notifies all the subscribers to ev->type
		void notify(const GameObject* sender, const Event* ev) const;

	private:
		// Each type of event has a vector of attached subscribers to notify
		std::unordered_map<Event::EventType, std::vector<IObserver*>> m_subscribers;

		bool keyExists(const Event::EventType evType) const;
		bool isSubscribed(const IObserver* const subscriber, const Event::EventType evType) const;
	};
}