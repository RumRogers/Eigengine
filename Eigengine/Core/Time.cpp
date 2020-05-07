#include "Time.h"

namespace EigenCore
{
	float Time::m_deltaTime = 0.f;
	float Time::m_fixedDeltaTime = (1000.f / 60.f); // defaulting at 60FPS for now
	float Time::m_timeScale = 1.f;
}