#pragma once
#include "../Core/Component.h"
namespace BulletDream {
	class Collider_AABB : Component {
	private:
		vec size;
	public:
		Collider_AABB::Collider_AABB(GameObject* owner);
		Collider_AABB::Collider_AABB(GameObject* owner, vec& size);

		Collider_AABB::~Collider_AABB();

		vec getSize() const;
		void setSize(vec size);
	};
}


