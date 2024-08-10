#include "Table.h"

namespace database::domain
{

Table::Table(const TableData& data)
{
}

std::string Table::GetByIndex(size_t index) const
{
	return std::string();
}

void Table::Add(std::string_view value)
{
}

void Table::Update(size_t index, std::string_view value)
{
}

} // namespace database::domain