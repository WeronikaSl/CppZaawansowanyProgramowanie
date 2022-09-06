#pragma once
#include <string>
#include <vector>
#include <fstream>

class EmployeeFileReader
{
private:
	void isOpened(const std::ifstream& file) const;
public:
	std::vector<std::string> readFromFile(std::ifstream& file) const;
};