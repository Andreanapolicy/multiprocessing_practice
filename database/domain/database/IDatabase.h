#pragma once
#include "../table/ITable.h"
#include <memory>

namespace database::domain
{
class IDatabase
{
public:
	virtual [[nodiscard]] const ITable& GetTable(std::string_view name) const = 0;
	virtual [[nodiscard]] ITable& GetTable(std::string_view name) = 0;
	virtual void AddTable(std::string_view name) = 0;

	virtual ~IDatabase() = default;
};
} // namespace database::domain