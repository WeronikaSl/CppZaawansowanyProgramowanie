#pragma once
#include "EmployeeWriterAbstractClass.hpp"
#include "Employee.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class EmployeeFileWriter : public EmployeeWriterAbstract
{
private:
	void isOpened(const std::ofstream& file) const;
	std::vector<std::string> getDataForPasswordsFile(std::vector<Employee> vec) const;
public:
	void writeToFile(std::vector<Employee> vec, std::ofstream& file) const override;

};