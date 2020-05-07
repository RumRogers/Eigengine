#pragma once

namespace EigenCore
{
	class GameObject;
	class Event;

	// Observer pattern: each concrete observer must implement the pure virtual handleEvent method
	class IObserver
	{
	public:
		virtual void handleEvent(const GameObject* sender, const Event* event) = 0;
	};
}

