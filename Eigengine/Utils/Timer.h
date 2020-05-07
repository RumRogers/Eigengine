#pragma once

#include <chrono>

namespace EigenUtils
{
	using TimePoint = std::chrono::high_resolution_clock::time_point;

	class Timer
	{
	public:
		Timer() : m_elapsedTime(0), m_running(false) {}
		inline void start()
		{
			if (!m_running)
			{
				m_running = true;
				m_lastTimePoint = std::chrono::high_resolution_clock::now();
			}
		}
		
		inline void stop()
		{
			if (m_running)
			{
				m_running = false;
				TimePoint now = std::chrono::high_resolution_clock::now();
				std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_lastTimePoint);
				m_elapsedTime = duration.count();
			}
		}
		inline float getElapsedTime() const
		{
			return m_elapsedTime;
		}
	private:
		float m_elapsedTime;
		TimePoint m_lastTimePoint;
		bool m_running;

	};
}