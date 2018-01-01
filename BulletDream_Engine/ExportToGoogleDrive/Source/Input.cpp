#include "../Include/Core/Input.h"

vector<KeyCode> Input::keyList = {};
vector<KeyCode> Input::keyDownList = {};
vector<KeyCode> Input::keyUpList = {};

inline bool Input::keyIsInList(vector<KeyCode>& keylist, KeyCode key) {
	return std::find(keyList.begin(), keyList.end(), key) != keyList.end();
}

inline void Input::removeListKeyByValue(vector<KeyCode>& keylist, KeyCode key) {
	keylist.erase(std::remove(keylist.begin(), keylist.end(), key), keylist.end());
}

const vector<KeyCode>& Input::getKeyList() {
	return keyList;
}
const vector<KeyCode>& Input::getKeyDownList() {
	return keyDownList;
}

const vector<KeyCode>& Input::getKeyUpList() {
	return keyUpList;
}

bool Input::getKey(KeyCode key) {
	return std::find(keyList.begin(), keyList.end(), key) != keyList.end();
}

bool Input::getKeyDown(KeyCode key) {
	return std::find(keyDownList.begin(), keyDownList.end(), key) != keyDownList.end();
}

bool Input::getKeyUp(KeyCode key) {
	return std::find(keyUpList.begin(), keyUpList.end(), key) != keyUpList.end();
}

void Input::update() {

	//Maak de keyUpList leeg
	keyUpList.clear();

	for(int i = 0; i < KeyCode::KeyCount; i++) {
		const KeyCode key = (KeyCode)i;

		//Keydown check
		const bool currentKeyIsPressed = Keyboard::isKeyPressed(key);
		if(currentKeyIsPressed) {
			if(!getKeyDown(key) && !keyIsInList(keyList, key)) {
				keyDownList.push_back(key); //toetsknop wordt in de keyDownList lijst gestopt.
				keyList.push_back(key);
			}
			else {
				removeListKeyByValue(keyDownList, key); //Verwijder het toetsknop uit de keyDownList.
			}
		}
		//KeyUp check
		else{
			if(getKeyDown(key)) {
				removeListKeyByValue(keyDownList, key); //Verwijder het toetsknop uit de keyDownList.
			}
			if(getKey(key)&&!getKeyUp(key)) {
				keyUpList.push_back(key); //toetsknop wordt in de keyUpList lijst gestopt.
			}
			removeListKeyByValue(keyList, key);
		}
	}
}