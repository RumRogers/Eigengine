#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Core/Game.h"

TEST_CASE("Game run")
{
	EigenCore::Game game;

	if (game.initGame())
	{
		game.gameLoop();
	}
}