#include "EmployeeManagerClass.hpp"


bool EmployeeManager::ifLoginExists(std::string login)
{
	int countLogins = 0;
	auto lambda = [&](Employee employee)
	{
		if (employee.getLogin() == login)
		{
			countLogins++;
		}
	};

	std::for_each(_employees.begin(), _employees.end(), lambda);

	return (countLogins > 0);
}

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

	auto lambda = [&](Employee& employee)
	{
		x = (employee.getFirstName()).at(0);
		tempLogin.push_back(std::tolower(x));

		x = (employee.getFirstName()).at(1);
		tempLogin.push_back(std::tolower(x));

		x = (employee.getLastName()).at(0);
		tempLogin.push_back(std::tolower(x));

		x = (employee.getLastName()).at(1);
		tempLogin.push_back(std::tolower(x));

		int size = (employee.getLastName()).size();

		for (size_t i = 2; i < size; ++i)
		{
			if (ifLoginExists(tempLogin) == false)
			{
				break;
			}
			x = (employee.getLastName()).at(i);
			tempLogin.push_back(std::tolower(x));
		}

		char a = '1';
		while (ifLoginExists(tempLogin) == true)
		{
			tempLogin.push_back(a);
			a++;
			if (a > 57)
			{
				break;
			}
		}
		
		employee.setLogin(tempLogin);
		tempLogin.clear();
	};
	std::for_each(_employees.begin(), _employees.end(), lambda);
}