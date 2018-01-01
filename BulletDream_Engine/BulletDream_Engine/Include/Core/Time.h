#pragma once
#include <SFML/System.hpp>
#include <vector>
#include "EngineDefinitions.h"

static class Time {
private:
	static sf::Clock deltaTimeClock;
	static sf::Clock timeClock;
	static unsigned long long frameCount;
	static double deltaTime;

	Export static double maxDeltaTime;

	Export static const unsigned long long FRAME_COUNT_MAX;
public:
	Export static float getDeltaTime(); //Geef tijd van de laatste frame terug
	Export static float getPassedTime();
	Export static unsigned long long getFrameCount(); //Geef het aantal frames terug
	static void update();
};