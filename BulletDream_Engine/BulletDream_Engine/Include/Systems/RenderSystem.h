#pragma once

#pragma once
#include "../Core/System.h"

namespace BulletDream {
	class RenderSystem : System {
	public:
		RenderSystem() {}
		~RenderSystem() {}

		Export virtual void update(Engine* engine);
	};
}
