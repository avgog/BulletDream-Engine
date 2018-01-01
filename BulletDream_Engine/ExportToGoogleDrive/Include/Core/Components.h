#pragma once
//#include "Component.h"
#include "EngineDefinitions.h"
#include "GameObject.h"
#include "Component.h"

namespace BulletDream {

	template<typename T>
	class Components {
	private:
		//maak de constructor private
		Components() {

		}
	public:
		static T* add(GameObject* obj) {
			T* comp = dynamic_cast<T*>(obj->components[TYPE_ID(T)]);
			if (comp != nullptr) {
				delete comp;
			}
			comp = new T(obj);
			obj->components[TYPE_ID(T)] = dynamic_cast<Component*>(comp);
			return comp;
		}

		static T* get(GameObject* obj) {
			T* comp = dynamic_cast<T*>(obj->components[TYPE_ID(T)]);

			return comp;
		}

		static void remove(GameObject* obj) {
			T* comp = dynamic_cast<T*>(obj->components[TYPE_ID(T)]);
			if (comp != nullptr) {
				delete comp;
			}
			obj->components.erase(TYPE_ID(T));
		}
	};
}
