#pragma once
#include <functional>
#include <unordered_map>

namespace EigenCore
{
	class GameObject;
	class Event;

	typedef std::function<void(GameObject*, Event*)> Callback;

	// Observer pattern
	class Subject
	{
	public:
		void attach(const GameObject* subscriber, const Callback callback);
		void detach(const GameObject* subscriber);
		void notify(const GameObject* sender, const Event* ev) const;
	
	private:

	};
}

