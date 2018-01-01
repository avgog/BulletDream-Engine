#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/System/String.hpp>
#include <iostream>

#define Export __declspec(dllexport)
typedef unsigned int uint;
typedef sf::Vector2f vec;
typedef sf::String string;
#define TYPE_ID(T) &typeid(T*)
#define TYPE_DATA const std::type_info
#define ENABLE_IF_SAMETYPE(T1, T2) typename std::enable_if<std::is_same<T1, T2>::value>::type