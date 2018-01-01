#pragma once

#include "RenderComponent.h"

namespace BulletDream {
	class Sprite : public RenderComponent {
	public:
		sf::Color color = sf::Color::White;

		sf::Texture texture;
		Export Sprite(GameObject* owner);

		virtual void render(sf::RenderWindow& window);

		virtual void update() {

		}

		Export virtual Component* copy(GameObject* owner) {
			Sprite* clone = new Sprite(owner);
			clone->color = this->color;
			clone->texture = this->texture;
			return clone;
		}
	};
}