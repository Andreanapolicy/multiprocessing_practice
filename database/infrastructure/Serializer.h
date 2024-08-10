#pragma once
#include <string_view>
#include "../domain/database/Database.h"

namespace database::infrastructure
{
using RawDatabase = domain::DatabaseData;
using RawTableData = domain::TableData;

class Serializer
{
public:
	static [[nodiscard]] RawDatabase GetDatabase(std::string_view filename);
};
} // namespace database::infrastructure