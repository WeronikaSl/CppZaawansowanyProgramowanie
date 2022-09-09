#pragma once
#include <vector>
#include <fstream>

class EmployeeWriterAbstract
{
public:
	virtual void writeToFile(std::vector<std::string> text, std::ofstream& file) const = 0;
	virtual ~EmployeeWriterAbstract() = default;
};