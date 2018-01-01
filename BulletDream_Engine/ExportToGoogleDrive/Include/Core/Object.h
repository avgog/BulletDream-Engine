#pragma once
#include "EngineDefinitions.h";

namespace BulletDream {
	class Object {
	private:
		uint id;
		static uint newId;

	public:
		Object();
		Object(const Object& original);
		Object operator=(const Object& other);

		uint getId() const;
	};

	template<typename T>
	class ObjectPtr {
		static_assert(std::is_base_of<Object, T>::value, "T must be a descendant of Object");

		T* ptr = nullptr; //pointer naar object
		uint id = 0; //opgeslagen id

		ObjectPtr() {

		}

		ObjectPtr(T* ptr) {
			set(ptr);
		}

		Export void set(T* ptr) {
			this->ptr = ptr;
			id = ptr->;
		}

		Export T* get() {
			if (ptr != nullptr && static_cast<Object*>(ptr)->getId() == id) {
				return ptr;
			}
			return nullptr;
		}
	};
}

