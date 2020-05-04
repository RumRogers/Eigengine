#pragma once
#include <functional>
#include <unordered_map>

namespace EigenCore
{
	class GameObject;
	class EigenEvent;

	typedef std::function<void(GameObject*, EigenEvent*)> Callback;

	// Observer pattern
	class Subject
	{
	public:
		void attach(const GameObject* subscriber, const Callback callback);
		void detach(const GameObject* subscriber);
		void notify(const GameObject* sender, const EigenEvent* ev) const;
	
	private:

	};
}

