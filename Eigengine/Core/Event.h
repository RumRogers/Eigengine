#pragma once

namespace EigenCore
{
	class Event
	{		
	public:
		typedef enum class EventType
		{
			SOME_EVENT
		} EventType;

		EventType type;
	public:
		explicit Event(const EventType evType) : type(evType) {}
	};
}