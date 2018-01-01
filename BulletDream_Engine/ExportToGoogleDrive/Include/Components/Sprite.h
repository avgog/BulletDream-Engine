#pragma once

#include "RenderComponent.h"

namespace BulletDream {
	class Sprite : public RenderComponent {
	public:
		sf::Color color = sf::Color::White;

		sf::Texture texture;
		Export Sprite(GameObject* owner);

		void render(sf::RenderWindow& window);
	};
}