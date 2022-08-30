#pragma once
#include <string>
#include <algorithm>
#include <list>

class StringConverter
{
public:
	static std::string toSnakeCase(std::string str);
	static std::string toCamelCase(std::string str);
};