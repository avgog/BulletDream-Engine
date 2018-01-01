#pragma once
#include "EngineDefinitions.h"
#include "Object.h"
#include "GameObject.h"

namespace BulletDream {
	//component base class (abstract)
	class Component : public Object {
	private:
		GameObject* const owner;
	public:
		Export Component(GameObject* owner);
		virtual Export ~Component();

		virtual void update() = 0;
		Export GameObject* getOwner();
	};
}
