#pragma once

namespace EigenCore
{
	typedef enum class EventType
	{
		SOME_EVENT
	} EventType;

	class Event
	{
	public:
		EventType type;
	public:
		explicit Event(const EventType evType) : type(evType) {}
	};
}