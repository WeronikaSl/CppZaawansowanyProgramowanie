#include "EmployeeFileReaderClass.hpp"

void EmployeeFileReader::isOpened(const std::ifstream& file) const 
{
	if (!file.is_open())
	{
		throw std::runtime_error("Nie można otworzyć pliku!");
	}
}

std::vector<std::string> EmployeeFileReader::readFromFile(std::ifstream& file) const
{
	isOpened(file);
	std::vector<std::string> text = {};
	std::string lineInText = {};
	while (file.good() && !file.eof())
	{
		std::getline(file, lineInText);
		text.push_back(lineInText);
	}

	file.close();
	return text;
}

std::vector<Employee> EmployeeFileReader::getEmployees(std::ifstream& file) const
{
	std::vector<std::string> textCSV = readFromFile(file);
	std::vector<Employee> vecOfEmployees = {};
	Employee tempEmployee;
	auto lambda = [&](std::string line)
	{
		std::stringstream ss(line);
		std::string tempString;
		
		if (std::getline(ss, tempString, ','))
		{
			tempEmployee.setFirstName(tempString);
		}
		if (std::getline(ss, tempString, ','))
		{
			tempEmployee.setLastName(tempString);
		}
		if (std::getline(ss, tempString, ','))
		{
			tempEmployee.setEmail(tempString);
		}
		if (std::getline(ss, tempString, ','))
		{
			if (tempString == "Female")
			{
				tempEmployee.setGender(Employee::Gender::FEMALE);

			}
			else if (tempString == "Male")
			{
				tempEmployee.setGender(Employee::Gender::MALE);
			}
			else
			{
				tempEmployee.setGender(Employee::Gender::UNKNOWN);
			}
		}
		if (std::getline(ss, tempString, ','))
		{
			tempEmployee.setSalary(std::stod(tempString));
		}
		vecOfEmployees.push_back(tempEmployee);
	};
	auto begin = textCSV.begin();
	std::advance(begin, 1);
	std::for_each(begin, textCSV.end(), lambda);

	return vecOfEmployees;
}
