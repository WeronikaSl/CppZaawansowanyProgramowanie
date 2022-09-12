#include "EmployeeJSONWriterPasswordsClass.hpp"


	void EmployeeJSONWriterPasswords::writeToFile(std::vector<Employee> data, std::ofstream& file) const
	{
		json j;
		j["Employees"] = data;
		file << std::setw(4) << j << std::endl;

	}

	void to_json(json& j, const Employee& p)
	{
		j = json{ {"Email", p.getEmail()},
				{"Login", p.getLogin()},
				{"Password", p.getPassword()} };

	}

