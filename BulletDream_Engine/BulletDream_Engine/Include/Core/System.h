#pragma once
#include "EngineDefinitions.h"

namespace BulletDream {
	extern class Engine;

	class System {
	public:
		System() {}
		Export virtual void update(Engine* engine) = 0;
	};
}

#include "Engine.h"
