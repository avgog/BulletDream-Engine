#include "../Include/Components/Sprite.h"

using namespace BulletDream;

Sprite::Sprite(GameObject* owner) : RenderComponent(owner) {
	
}

void Sprite::render(sf::RenderWindow& window) {
	auto pos = this->getOwner()->getPosition();
	auto size = this->getOwner()->getSize();
	float angle = this->getOwner()->getAngle();

	sf::RectangleShape rect = sf::RectangleShape(size);
	rect.setPosition(pos);
	rect.setOrigin(size * 0.5f);
	rect.setRotation(angle);
	rect.setFillColor(color);
	rect.setTexture(&this->texture);

	window.draw(rect);
}