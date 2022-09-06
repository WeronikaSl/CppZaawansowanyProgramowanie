#include "EmployeeFileWriter.hpp"

void EmployeeFileWriter::isOpened(const std::ofstream& file) const
{
	if (!file.is_open())
	{
		throw std::runtime_error("Nie można otworzyć pliku!");
	}
}

void EmployeeFileWriter::writeToFile(std::vector<std::string> text, std::ofstream& file)
{
	isOpened(file);
	for (auto it = text.cbegin(); it < text.cend(); ++it)
	{
		if (file.good())
		{
			file << *it;
		}
	}
	file.close();
}
