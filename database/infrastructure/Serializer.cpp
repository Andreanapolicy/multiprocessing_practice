#include "Serializer.h"
#include <filesystem>
#include <fstream>
#include <sstream>

namespace database::infrastructure
{
RawDatabase Serializer::GetDatabase(std::string_view filename)
{
	std::ifstream file;

	auto path = std::filesystem::current_path();
	path += filename.data();
	file.open(path);

	if (!file.is_open())
	{
		throw std::runtime_error("error"); // TODO: add custom exception
	}

	std::string line;
	RawDatabase database;
	while (std::getline(file, line))
	{
		std::istringstream iss{ line };

		std::string tableName;
		std::string temp;

		if (iss >> temp && temp != "Table:")
		{
			throw std::runtime_error("error"); // TODO: add custom exception
		}

		iss >> tableName;
		RawTableData tableData;
		while (std::getline(file, line) && !line.empty())
		{
			std::istringstream iss{ line };

			std::string key;
			std::string value;
			std::string separator;

			if (iss >> key && iss >> separator && iss >> value && separator != ":")
			{
				throw std::runtime_error("error"); // TODO: add custom exception
			}
			tableData.emplace(key, value);
		}

		database.emplace(tableName, tableData);
	}

	return database;
}

} // namespace database::infrastructure