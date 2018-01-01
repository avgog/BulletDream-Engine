#pragma once

#include <SFML\Graphics.hpp>
#include <algorithm>
#include <vector>
#include "EngineDefinitions.h"

using sf::Keyboard;
using std::vector;
typedef Keyboard::Key KeyCode;

static class Input {
private:
	static vector<KeyCode> keyList;
	static vector<KeyCode> keyDownList;
	static vector<KeyCode> keyUpList;

	static inline bool keyIsInList(vector<KeyCode>& keylist, KeyCode key);
	static inline void removeListKeyByValue(vector<KeyCode>& keylist, KeyCode key);
public:
	static const vector<KeyCode>& getKeyList();
	static const vector<KeyCode>& getKeyDownList();
	static const vector<KeyCode>& getKeyUpList();

	static Export bool getKey(KeyCode key);

	static Export bool getKeyDown(KeyCode key);

	static Export bool getKeyUp(KeyCode key);

	static void update();
};