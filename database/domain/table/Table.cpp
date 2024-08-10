#include "Table.h"

namespace database::domain
{

Table::Table(const TableData& data)
	: m_data{ data }
{
}

std::string Table::GetByKey(std::string_view key) const
{
	auto it = m_data.find(key.data());
	if (it == m_data.end())
	{
		return "";
	}

	return it->second;
}

void Table::Add(std::string_view value)
{
	// TODO: implement me
}

void Table::Update(size_t index, std::string_view value)
{
	// TODO: implement me
}

} // namespace database::domain