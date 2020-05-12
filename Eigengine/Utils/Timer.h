#pragma once

#include <chrono>

namespace EigenUtils
{
	using HiResClock = std::chrono::high_resolution_clock;
	using TimePoint = HiResClock::time_point;
	using Milliseconds = std::chrono::milliseconds;

	class Timer
	{
	public:
		Timer() : m_elapsedTime(0), m_running(false) {}
		inline void start()
		{
			if (!m_running)
			{
				m_running = true;
				m_lastTimePoint = HiResClock::now();
			}
		}
		
		inline void stop()
		{
			if (m_running)
			{
				m_running = false;
				
				m_elapsedTime = computeElapsedTime();
			}
		}
		inline float getElapsedTime() const
		{
			if (m_running)
			{
				return computeElapsedTime();
			}

			return m_elapsedTime;
		}
	private:
		float m_elapsedTime;
		TimePoint m_lastTimePoint;
		bool m_running;

		inline float computeElapsedTime() const
		{
			TimePoint now = HiResClock::now();
			Milliseconds duration = std::chrono::duration_cast<Milliseconds>(now - m_lastTimePoint);
			return static_cast<float>(duration.count());
		}
	};
}