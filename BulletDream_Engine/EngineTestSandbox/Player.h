#pragma once

#include <Core/Input.h>
#include <Core/Component.h>
#include <Components/Sprite.h>

using namespace BulletDream;

class Player : public Component {
public:
	float speed = 100;

	Player(GameObject* owner) : Component(owner) {

	}

	void update() {
		vec movement;
		sf::Color color;
		auto rect = this->getOwner()->getComponent<Sprite>();
		const float dt = Time::getDeltaTime();

		if (rect) {
			color = rect->color;
		}

		if (Input::getKey(KeyCode::A)) {
			movement += vec(-1, 0) * speed * dt;
			color = sf::Color::Red;
		}
		if (Input::getKey(KeyCode::D)) {
			movement += vec(1, 0) * speed * dt;
			color = sf::Color::Yellow;
		}
		if (Input::getKey(KeyCode::W)) {
			movement += vec(0, -1) * speed * dt;
			color = sf::Color(0, 0, 0, 100);
		}
		if (Input::getKey(KeyCode::S)) {
			movement += vec(0, 1) * speed * dt;
			color = sf::Color::Magenta;
		}

		if (Input::getKey(KeyCode::Q)) {
			this->getOwner()->setAngle(this->getOwner()->getAngle() - 1);
		}
		else if (Input::getKey(KeyCode::E)) {
			this->getOwner()->setAngle(this->getOwner()->getAngle() + 1);
		}

		this->getOwner()->move(movement);

		if (rect) {
			rect->color = color;
		}
	}

	Component* copy(GameObject* owner) {
		Player* clone = new Player(owner);
		clone->speed = this->speed;
		return clone;
	}
};