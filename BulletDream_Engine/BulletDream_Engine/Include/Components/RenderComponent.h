#pragma once
#include "../Core/Component.h"
#include "SFML/Graphics.hpp"

namespace BulletDream {
	class RenderComponent : public Component {
	public:
		RenderComponent(GameObject* owner) : Component(owner) {
			
		}

		virtual ~RenderComponent() {

		}

		virtual void render(sf::RenderWindow& window) = 0;

		virtual void update() = 0;

		Export virtual Component* copy(GameObject* owner) = 0;
	};
}