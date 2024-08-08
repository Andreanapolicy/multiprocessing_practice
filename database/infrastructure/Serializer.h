#pragma once
#include <map>
#include <string>

namespace database::infrastructure
{

using RawTableData = std::map<std::string, std::string>;
using RawDatabase = std::map<std::string, RawTableData>;

class Serializer
{
	static [[nodiscard]] RawDatabase GetDatabase(std::string_view filename);
};
} // namespace database::infrastructure