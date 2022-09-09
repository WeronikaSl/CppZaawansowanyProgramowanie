#include "EmployeeManagerClass.hpp"


bool EmployeeManager::ifLoginExists(std::string login) const
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

int EmployeeManager::draw(int a, int b) const
{
	std::random_device r;
	std::default_random_engine e(r());
	std::uniform_int_distribution<int> distr(a, b);
	return distr(e);
}

bool EmployeeManager::ifCorrectChar(char a) const
{
	bool condition1 = ((a >= '0') && (a <= '9'));
	bool condition2 = ((a >= 'A') && (a <= 'Z'));
	bool condition3 = ((a >= 'a') && (a <= 'z'));
	bool condition4 = (a == '!');
	bool condition5 = (a == '?');
	bool condition6 = (a == '@');
	bool condition7 = (a == '+');
	bool condition8 = (a == '=');
	bool condition9 = (a == '-');
	bool condition10 = ((a >= '#') && (a <= '&'));
	bool mainCondition = condition1 || condition2 || condition3 || condition4 || condition5
		|| condition6 || condition7 || condition8 || condition9 || condition10;
	return mainCondition;
}

void EmployeeManager::regexForPassword(std::string& password) const
{
	std::regex passwordRegex ("^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[!?@#$%&+=-]).{8,12}$");
	if (false == std::regex_match(password, passwordRegex))
	{
		password.clear();
	}
}

EmployeeManager::EmployeeManager(std::vector<Employee> employees)
{
	_employees = employees;
}

std::vector<Employee> EmployeeManager::getEmployees() const
{
	return _employees;
}

void EmployeeManager::generateLogins()
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

void EmployeeManager::generatePasswords()
{
	int passwordLength = draw(8, 12);
	std::string password = {};
	char drawnChar = 'a';

	auto lambda = [&](Employee& empl)
	{
		do
		{
			drawnChar = draw(33, 122);

			if (ifCorrectChar(drawnChar))
			{
				password.push_back(drawnChar);
			}

			if (password.size() == passwordLength)
			{
				regexForPassword(password);
			}
		}while (passwordLength != password.size());

		empl.setPassword(password);
		password.clear();
	};
	
	std::for_each(_employees.begin(), _employees.end(), lambda);

}

std::vector<std::string> EmployeeManager::getDataForPasswordsFile() const
{
	std::vector<std::string> data = {};
	std::stringstream ss;

	auto lambda = [&](Employee employee)
	{
		ss  << employee.getLogin() << ","
			<< employee.getEmail() << ","
			<< employee.getPassword() << "\n";
			
		data.push_back(ss.str());
		ss.str(std::string()); 
	};
	std::for_each(_employees.cbegin(), _employees.cend(), lambda);

	return data;
}


