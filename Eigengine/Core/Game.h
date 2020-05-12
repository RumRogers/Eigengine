#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Utils/Logger.h"

namespace EigenUtils { class Timer; }

class Scene;
struct SDL_Window;
struct SDL_Renderer;

namespace EigenCore
{
	class Game final
	{
	public:
		explicit Game(const size_t winW = 800, const size_t winH = 600,
			const std::string winTitle = "Eigengine", const size_t targetFPS = 60, const size_t maxFrameSkip = 5) :
			m_winW(winW),
			m_winH(winH),
			m_winTitle(winTitle),
			m_targetFPS(targetFPS),			
			m_idealFrameDurationInMillis(1000 / targetFPS),
			m_maxFrameSkip(maxFrameSkip),
			m_maxDelay(maxFrameSkip * m_idealFrameDurationInMillis),
			m_quit(false),
			m_timer(nullptr),
			m_window(nullptr),
			m_renderer(nullptr),
			m_currentScene(nullptr) {}

		~Game() { EigenUtils::Logger::Log("Cleaning game..."); shutdown(); }

		bool initGame();
		void gameLoop();

	private:
		size_t m_winW;
		size_t m_winH;
		std::string m_winTitle;
		size_t m_targetFPS;
		size_t m_idealFrameDurationInMillis;
		size_t m_maxFrameSkip;
		size_t m_maxDelay;
		bool m_quit;
		EigenUtils::Timer* m_timer;
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		Scene* m_currentScene;
		std::vector<Scene*> m_scenes;
		
		void getInput();
		void update(const float dt);
		void render();
		void shutdown();
	};
}