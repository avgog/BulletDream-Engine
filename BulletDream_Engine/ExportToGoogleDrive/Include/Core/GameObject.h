#pragma once
#include "EngineDefinitions.h"
#include "Object.h"
#include <unordered_map>
#include "Time.h"

namespace BulletDream {
	extern class Component;

	class GameObject : public Object {
	private:
		vec position;
		float angle;
		vec size;
	public:
		bool enabled = true;
		string name;
		string tag;
		std::unordered_map<TYPE_DATA*, Component*> components;
	public:
		Export GameObject();
		Export GameObject(string& name);
		Export GameObject(vec position, float angle, vec size);

		Export ~GameObject();

		Export const string& getName() const;

		Export vec getPosition() const;
		Export void setPosition(vec newPos);
		Export void move(vec movement);

		Export float getAngle() const;
		Export void setAngle(float newAngle);

		Export vec getSize() const;
		Export void setSize(vec newSize);

		template<class T>
		Export T* addComponent() {
			return Components<T>::add(this);
		}

		template<class T>
		Export T* getComponent() {
			return Components<T>::get(this);
		}

		template<class T>
		Export void removeComponent() {
			Components<T>::remove(this);
		}

		Export void removeAllComponents();
	};
}

#include "Components.h"