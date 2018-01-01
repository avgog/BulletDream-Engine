#pragma once

#include <Core/Engine.h>
#include <Core/Input.h>
#include <Core/Component.h>

using namespace BulletDream;

class LevelManager : public Component {
public:
	LevelManager(GameObject* owner) : Component(owner){

	}

	void update() {
		//Engine* engine = Engine::get();

		/*if (Input::getKeyDown(KeyCode::I)) {
			GameObject* playerEntity = new GameObject(vec(50, 50), 0, vec(50, 50));
			playerEntity->name = "player";
			playerEntity->addComponent<Player>();
			playerEntity->addComponent<RectangleSprite>();

			engine->initialise(playerEntity);
		}*/
	}
};
