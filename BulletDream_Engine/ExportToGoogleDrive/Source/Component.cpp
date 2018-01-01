#include "../Include/Core/GameObject.h"
#include "../Include/Core/Component.h"

using namespace BulletDream;

Component::Component(GameObject* owner) : owner(owner) {
	std::cout << "Base Component Init" << std::endl;
}

Component::~Component(){
	std::cout << "Base Component Destroy" << std::endl;
}

GameObject* Component::getOwner(){
	return owner;
}

