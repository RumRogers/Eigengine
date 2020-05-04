#pragma once

namespace EigenCore
{
	typedef enum class EventType
	{
		SOME_EVENT
	} EventType;

	class EigenEvent
	{
	public:
		EventType type;
	public:
		explicit EigenEvent(const EventType evType) : type(evType) {}
	};
}