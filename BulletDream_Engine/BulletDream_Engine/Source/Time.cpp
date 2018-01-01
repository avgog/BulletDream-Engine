#include "../Include/Core/Time.h"
#include <algorithm> //voor vector.remove()

sf::Clock Time::deltaTimeClock = sf::Clock();
unsigned long long Time::frameCount = 0;
double Time::deltaTime = 0;
double Time::maxDeltaTime = 1.0 / 20;
const unsigned long long Time::FRAME_COUNT_MAX = 18446744073709551615;

float Time::getDeltaTime() {
	return deltaTime;
}

float Time::getPassedTime() {
	return deltaTimeClock.getElapsedTime().asSeconds();
}
unsigned long long Time::getFrameCount() {
	return frameCount;
}

void Time::update() {

	deltaTime = deltaTimeClock.restart().asSeconds(); //Herstart de deltaTimeklok.
	if(deltaTime > maxDeltaTime) {
		deltaTime = maxDeltaTime;
	}

	if(frameCount < FRAME_COUNT_MAX) {
		frameCount++;
	}
}
