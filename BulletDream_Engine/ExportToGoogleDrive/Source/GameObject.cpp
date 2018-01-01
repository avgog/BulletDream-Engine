#include "../Include/Core/GameObject.h"
#include "../Include/Core/Component.h"

using namespace BulletDream;

GameObject::GameObject() {
	name = "GameObject_id_" + this->getId();
}

Export GameObject::GameObject(string& name) {
	this->name = name;
}

GameObject::GameObject(vec position, float angle, vec size) :
	position(position), angle(angle), size(size) 
{
	this->name = "GameObject_id_" + this->getId();
}

GameObject::~GameObject() {
	removeAllComponents();
}

const string& GameObject::getName() const {
	return name;
}

void GameObject::removeAllComponents() {
	while (this->components.size() > 0) {
		Component* comp = this->components.begin()->second;
		if (comp != nullptr) {
			delete comp;
		}
		this->components.erase(this->components.begin()->first);
	}
}

vec GameObject::getPosition() const {
	return position;
}

void GameObject::setPosition(vec newPos) {
	position = newPos;
}

void GameObject::move(vec movement) {
	position += movement;
}

float GameObject::getAngle() const {
	return angle;
}

void GameObject::setAngle(float newRot) {
	angle = newRot;
}

vec GameObject::getSize() const {
	return size;
}

void GameObject::setSize(vec newScale) {
	size = newScale;
}