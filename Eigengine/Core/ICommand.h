#pragma once

namespace EigenCore
{
	// Command pattern: each concrete command must implement the execute() pure virtual method
	class ICommand
	{
	public:
		virtual ~ICommand() {};
		virtual void execute() = 0;
	};
}