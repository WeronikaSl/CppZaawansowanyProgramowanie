#pragma once
#include "EmployeeWriterAbstractClass.hpp"
#include <fstream>
#include <string>
#include <vector>

class EmployeeFileWriter : public EmployeeWriterAbstract
{
private:
	void isOpened(const std::ofstream& file) const;
public:
	void writeToFile(std::vector<std::string> text, std::ofstream& file) const override;

};