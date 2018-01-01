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

		sf::RenderWindow* mainWindow = nullptr;
	public:
		Export Engine();
		Export ~Engine();
		Export void run();

		Export GameObject* initialise();
		Export GameObject* initialise(GameObject& obj);

		template<typename... ARG_T>
		Export GameObject* initialise_params(ARG_T ... args) {
			this->entities.emplace_back(&args...);
			return this->entities.back();
		}

		Export const std::vector<GameObject*>& getEntities() const {
			return this->entities;
		}

		Export sf::RenderWindow* getMainWindow() const {
			return this->mainWindow;
		}
	};
}


