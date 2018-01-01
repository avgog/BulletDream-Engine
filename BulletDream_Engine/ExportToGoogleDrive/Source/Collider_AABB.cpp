#include "../Include/Components/Collider_AABB.h"
using namespace BulletDream;


Collider_AABB::Collider_AABB(GameObject* owner) : Component(owner){
	
}

Collider_AABB::Collider_AABB(GameObject* owner, vec& size) : Component(owner), size(size) {

}

Collider_AABB::~Collider_AABB(){

}

vec Collider_AABB::getSize() const{
	return size;
}

void Collider_AABB::setSize(vec size) {
	this->size = size;
}