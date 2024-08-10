#include "Database.h"
#include "../table/Table.h"
#include <vector>

namespace database::domain
{

class Database::Impl
{
public:
	Impl(const DatabaseData& data)
	{
		for (auto& [tableName, tableData] : data)
		{
			m_data.emplace(tableName, std::make_unique<Table>(tableData));
		}
	}

	[[nodiscard]] const ITable& GetTable(std::string_view name) const
	{
		auto it = m_data.find(name.data());
		if (it == m_data.end())
		{
			throw std::exception("invalid argument");
		}
		return *(it->second);
	};

	[[nodiscard]] ITable& GetTable(std::string_view name)
	{
		auto it = m_data.find(name.data());
		if (it == m_data.end())
		{
			throw std::exception("invalid argument");
		}
		return *(it->second);
	}

	void AddTable(std::string_view name)
	{
		// TODO: implement me
	}

private:
	std::map<std::string, std::unique_ptr<Table>> m_data;
};

Database::Database(const DatabaseData& data)
	: m_impl{ std::make_unique<Impl>(data) }
{
}

Database::~Database() = default;

const ITable& Database::GetTable(std::string_view name) const
{
	return m_impl->GetTable(name);
}

ITable& Database::GetTable(std::string_view name)
{
	return m_impl->GetTable(name);
}

void Database::AddTable(std::string_view name)
{
	return m_impl->AddTable(name);
}

} // namespace database::domain