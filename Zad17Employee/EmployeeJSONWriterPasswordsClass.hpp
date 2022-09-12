#pragma once
#include "Employee.hpp"
#include "EmployeeWriterAbstractClass.hpp"
#include "json/json.hpp"

using json = nlohmann::json;


	class EmployeeJSONWriterPasswords : public EmployeeWriterAbstract
	{
	public:
		void writeToFile(std::vector<Employee> data, std::ofstream& file) const override;
	};

	void to_json(json& j, const Employee& p);
