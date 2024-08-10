#pragma once
#include "../table/ITable.h"
#include <memory>

namespace database::domain
{
class IDatabase
{
public:
	virtual [[nodiscard]] std::unique_ptr<ITable> GetTable(std::string_view name) = 0;
	virtual void AddTable(std::string_view name) = 0;
};
} // namespace database::domain