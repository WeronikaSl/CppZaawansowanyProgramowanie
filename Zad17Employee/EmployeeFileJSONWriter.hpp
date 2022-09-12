#pragma once
#include "EmployeeWriterAbstractClass.hpp"
#include "Employee.hpp"
#include "json/json.hpp"

using json = nlohmann::json;


	class EmployeeWriterJSON : public EmployeeWriterAbstract
	{
	public:
		void writeToFile(std::vector<Employee> data, std::ofstream& file) const override;
	};

	void to_json(json& j, const Employee& p);


