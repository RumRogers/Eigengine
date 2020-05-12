#pragma once

#include "../Utils/Timer.h"

using namespace EigenUtils;

namespace EigenCore
{
	class Time final
	{
	private:
		static float m_deltaTime;
		static float m_fixedDeltaTime;
		static float m_timeScale;

	public:
		inline static float deltaTime() { return m_deltaTime * m_timeScale; }
		inline static float fixedDeltaTime() { return m_fixedDeltaTime; }
		inline static float unscaledDeltaTime() { return m_deltaTime; }
		inline static float getTimeScale() { return m_timeScale; }
		inline static float setTimeScale(const float timeScale) { m_timeScale = timeScale; }

		friend class Game;
	};
}