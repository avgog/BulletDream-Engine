#include "../Include/Core/Engine.h"
#include "../Include/Components/RenderComponent.h"
#include "../Include/Core/Input.h"
#include "../Include/Core/InitDataLoader.h"
#include "../Include//Systems/RenderSystem.h"
#include <fstream> //voor het lezen van bestanden

using namespace BulletDream;

Engine::Engine(){
	sf::String str("Engine has been initialised");
	std::cout << (std::string)str << std::endl;
}


Engine::~Engine(){
	std::cout << "Quitting engine..." << std::endl;

	//verwijder alle gameobjecten
	for (int i = 0; i < entities.size(); i++) {
		GameObject* obj = entities[i];

		if (obj != nullptr) {
			printf("del gameObj start\n");
			delete obj;
			printf("del gameObj end\n");

		}
	}

	std::cout << "Engine Destructor has finished!" << std::endl;
}

void Engine::manageWindowEvents(sf::RenderWindow& window){
	sf::Event event;

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void Engine::updateComponents() {
	int entityCount = entities.size();
	for (int e = 0; e < entityCount; e++) {
		GameObject* entity = entities[e];
		if (entity != nullptr) {
			for (auto comp : entity->components) {
				if (comp.second) {
					comp.second->update();
				}
			}
		}
	}
}

GameObject* Engine::initialise() {
	this->entities.push_back(new GameObject());
	return this->entities.back();
}

GameObject* Engine::initialise(GameObject& obj) {
	this->entities.push_back(new GameObject(obj));
	return this->entities.back();
}

void Engine::run() {
	std::cout << "Running engine..." << std::endl;

	int framerateLimit = 60;
	int res_width = 1280;
	int res_height = 720;
	const char* windowTitle = "Bulletdream engine application";

	
	InitDataLoader engineConfig;
	if (engineConfig.LoadFile("Resources/engineInit.txt")) {
		framerateLimit = engineConfig.framerateLimit;
		res_width = engineConfig.resolutionWidth;
		res_height = engineConfig.resolutionHeight;
		windowTitle = engineConfig.window_title.c_str();
	}
	else {
		std::cout << "failed to read Resources/engineInit.txt." << std::endl;
	}

	sf::RenderWindow window(sf::VideoMode(res_width, res_height), windowTitle);
	window.setFramerateLimit(framerateLimit);
	this->mainWindow = &window;
	RenderSystem renderSystem;

	while (window.isOpen()) {
		manageWindowEvents(window); //handel window events
		Time::update();
		Input::update();
		updateComponents(); //update alle componenten
		renderSystem.update(this);

		if (Input::getKey(KeyCode::Escape)) {
			break;
		}

		//restart
		if (Input::getKey(KeyCode::Tab)) {
			break;
		}
	}
}