#pragma once
#include "../table/ITable.h"

namespace database::domain
{
class IDatabase
{
public:
	virtual [[nodiscard]] ITable& GetTable(std::string_view name) = 0;
	virtual void AddTable(std::string_view name) = 0;
};
} // namespace database::domain