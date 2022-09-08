#include "EmployeeManagerClass.hpp"


EmployeeManager::EmployeeManager()
{
	std::ifstream file("employee_input.csv");
	EmployeeFileReader reader;
	_employees = reader.getEmployees(file);
}

std::vector<Employee> EmployeeManager::getEmployees() const
{
	return _employees;
}

void EmployeeManager::generateLogin()
{
	std::string tempLogin = {};
	char x = 'a';

	for (auto it = _employees.begin(); it < _employees.end(); ++it)
	{
		x = ((*it).getFirstName()).at(0);
		tempLogin.push_back(std::tolower(x));
		x = ((*it).getFirstName()).at(1);
		tempLogin.push_back(std::tolower(x));
		x = ((*it).getLastName()).at(0);
		tempLogin.push_back(std::tolower(x));
		x = ((*it).getLastName()).at(1);
		tempLogin.push_back(std::tolower(x));
		(*it).setLogin(tempLogin);
		tempLogin.clear();
	}

}