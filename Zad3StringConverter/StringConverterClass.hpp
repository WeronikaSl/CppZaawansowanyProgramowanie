#pragma once
#include <string>
#include <algorithm>
#include <list>

class StringConverter
{
public:
	std::string toSnakeCase(std::string str);
	std::string toCamelCase(std::string str);
};