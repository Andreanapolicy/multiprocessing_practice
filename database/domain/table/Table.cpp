#include "Table.h"

namespace database::domain
{

Table::Table(const TableData& data)
	: m_data{ data }
{
}

std::string Table::GetByIndex(size_t index) const
{
	if (m_data.size() > index)
	{
		return "";
	}
	
	const auto it = m_data.begin();
	std::advance(it, index);

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