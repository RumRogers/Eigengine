#pragma once
#include <iostream>
#include <SDL.h>

namespace EigenUtils
{
	// For now it's just a wrapper to SDL_Log. Will change it in the future to avoid depending from SDL
	class Logger
	{
	public:
		static inline void Log(const std::string& msg)
		{
			Log(msg.c_str());
		}
		static inline void Log(const char* msg)
		{
			SDL_Log(msg);
		}
	};
}