#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "EngineDefinitions.h"
#include "GameObject.h"

namespace BulletDream {
	class Engine {
	private:
		std::vector<GameObject*> entities = {};

		void manageWindowEvents(sf::RenderWindow& window);
		void updateComponents();
		void renderScene(sf::RenderWindow& window);

	public:
		Export Engine();
		Export ~Engine();
		Export void run();

		Export void initialise(GameObject* obj);
	};
}


