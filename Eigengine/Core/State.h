#pragma once

namespace EigenCore
{
	// State pattern
	class State
	{
	public:
		// Each child class of State must specify what happens in its own update method
		virtual void update(const float dt) = 0;
	};
}
