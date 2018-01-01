#pragma once

#include <fstream>
#include <iostream>

namespace BulletDream {
	class InitDataLoader {
	public:
		int framerateLimit = 60;
		int resolutionWidth = 1280;
		int resolutionHeight = 720;
		std::string window_title = "NO_TITLE";

		bool LoadFile(const char* path);
	};
}
