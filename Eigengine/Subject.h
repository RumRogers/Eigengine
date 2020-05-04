#pragma once
#include <functional>
#include <unordered_map>
#include <vector>
#include "Core/EigenEvent.h"


namespace EigenCore
{
	class GameObject;

	typedef std::function<void(GameObject*, EigenEvent*)> Callback;

	// Observer pattern
	class Subject
	{
	public:
		
		// The GameObject requires to be notified when a specific event type occurs by calling the callback.
		void attach(const GameObject* subscriber, const EigenCore::EventType, const Callback callback);
		// The GameObject opts out of notifications for a specific event type
		void detach(const GameObject* subscriber, const EigenCore::EventType);
		// Notifies all the subscribers to ev->type
		void notify(const GameObject* sender, const EigenEvent* ev) const;
	
	private:
		// Each type of event has a vector of attached subscribers to notify
		std::unordered_map<EigenCore::EventType, std::vector<GameObject*>> m_subscribers;
	};
}