#include "Test_Timer.h"
#include <iostream>
#include <thread>
#include "../catch.hpp"
#include "../Utils/Timer.h"

//#define RUN_TEST_TIMER

namespace Tests
{
	float waitForMillisAndGetElapsedTime(int millis)
	{
		EigenUtils::Timer timer;
		timer.start();
		std::this_thread::sleep_for(std::chrono::milliseconds(millis));
		timer.stop();
		
		return timer.getElapsedTime();
	}

#ifdef RUN_TEST_TIMER
	TEST_CASE("Test_Timer", "[millis]")
	{
		float millisToWait = 1000.f / 60.f;
		std::cout << "Milliseconds to wait: " << millisToWait << ::std::endl;
		std::cout << "Waiting..." << std::endl;
		float millisWaited = Tests::waitForMillisAndGetElapsedTime(static_cast<int>(millisToWait));
		std::cout << "Time elapsed: " << millisWaited << std::endl;

		REQUIRE(millisToWait - millisWaited <= 1);
	}
#endif // RUN_TEST_TIMER
}
