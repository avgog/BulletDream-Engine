#pragma once

#include <iostream>
#include <SFML/System.hpp>

#define Export __declspec(dllexport)

namespace BulletDream {
	class Engine {
	private:
		Engine();

		static Engine* engine;
	public:
		~Engine();
		Export void run();

		static Export void init();
		static Export Engine* const get(); //geef een const pointer terug
		static Export void quit();
	};
}


