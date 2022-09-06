#pragma once
#include <fstream>
#include <string>
#include <vector>

class EmployeeFileWriter
{
private:
	void isOpened(const std::ofstream& file) const;
public:
	void writeToFile(std::vector<std::string> text, std::ofstream& file) const;

};