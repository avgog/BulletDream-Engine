#include <../Core/InitDataLoader.h>
#include <string>

using namespace BulletDream;

bool InitDataLoader::LoadFile(const char* path) {
	std::ifstream fs(path);
	if (fs.is_open()) {
		std::string line;
		while (std::getline(fs, line)) {
			auto pos = line.find(":");
			if (pos != std::string::npos) {
				std::string configname = line.substr(0, pos);
				std::string configValue = line.substr(pos + 1);

				while (configname.size() > 0 && configname.back() == ' ') {
					configname.pop_back(); //verwijder alle spaties aan het einde van de confignaam
				}

				while (configValue.size() > 0 && configValue[0] == ' ') {
					configValue.erase(configValue.begin()); //verwijder alle spaties aan het begin van de configval
				}

				if (configname == "framerate_limit") {
					framerateLimit = atoi(configValue.c_str());
				}
				else if (configname == "resolution_width") {
					resolutionWidth = atoi(configValue.c_str());
				}
				else if (configname == "resolution_height") {
					resolutionHeight = atoi(configValue.c_str());
				}
				else if (configname == "window_title") {
					window_title = configValue.c_str();
				}
			}
		}
		fs.close();
		return true;
	}
	else {
		return false;
	}
}