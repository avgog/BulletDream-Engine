// EngineTestSandbox.cpp : Defines the entry point for the console application.
//
//#include <>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <Core/Engine.h>
#include <Core/Input.h>
#include <Core/GameObject.h>
#include <Core/Component.h>
#include <Components/Sprite.h>

#include <SFML/System/String.hpp>

#include "Player.h"
#include "LevelManager.h"
#include <iostream>

using namespace BulletDream;

Engine* engine = nullptr;

void gameStartup() {
	GameObject playerEntity = GameObject(vec(100, 100), 0, vec(100, 100));
	playerEntity.name = "player";
	playerEntity.addComponent<Player>();
	Sprite* spriteComp = playerEntity.addComponent<Sprite>();
	if (!spriteComp->texture.loadFromFile("Resources/player.png")) {
		std::cout << "player.png doesnt exists" << std::endl;
	}

}



int main(){
	bool restart = false;
	do {
		restart = false;

		engine = new Engine();

		gameStartup();
		engine->run();

		if (Input::getKeyDown(KeyCode::Tab)) {
			restart = true;
		}

		delete engine;
	} while (restart);
	

    return 0;
}