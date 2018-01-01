#include "../Include/Core/Object.h"

using namespace BulletDream;

uint Object::newId = 0;

Object::Object() : id(++newId) {

}

Object::Object(const Object& original) : id(++newId) {

}

Object Object::operator=(const Object& other){
	return Object();
}

uint Object::getId() const {
	return id;
}