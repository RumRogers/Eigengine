#include "Game.h"
#include <SDL.h>
#include "../Utils/Timer.h"
#include "../Utils/Logger.h"

typedef EigenUtils::Logger Logger;

namespace EigenCore
{
	bool Game::initGame()
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			Logger::Log(std::string("Could not initialize SDL: ").append(SDL_GetError()));
			return false;
		}

		if (SDL_CreateWindow(m_winTitle.c_str(), 50, 50, m_winW, m_winH, 0) < 0)
		{
			Logger::Log(std::string("Could not initialize SDL: ").append(SDL_GetError()));
			return false;
		}

		m_timer = new EigenUtils::Timer();

		return true;
	}

	void Game::gameLoop()
	{
		float deltaTime{ 0 };
		m_timer->start();

		while(!m_quit)
		{	
			// Cap the framerate to the target FPS, do not go any faster
			while (m_timer->getElapsedTime() < m_idealFrameDurationInMillis);
			m_timer->stop();

			deltaTime = m_timer->getElapsedTime();
			// Do not skip too many frames, clearly can't keep up with the framerate
			if (deltaTime > m_maxDelay)
			{
				deltaTime = m_idealFrameDurationInMillis;
			}
			m_timer->start();

			getInput();
			update(deltaTime);
			render();
		}
	}
	void Game::getInput()
	{
		SDL_Event ev;
		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
			case SDL_QUIT:
				m_quit = true;
				break;
			default:
				break;
			}
		}
	}
	void Game::update(const float dt) { }
	void Game::render() {}

	
	void Game::shutdown()
	{
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);

		SDL_Quit();
	}
}