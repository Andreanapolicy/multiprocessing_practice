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
	}

private:
	std::map<std::string, std::unique_ptr<Table>> m_data;
};

Database::Database(const DatabaseData& data)
	: m_impl{ std::make_unique<Impl>(data) }
{
}

} // namespace database::domain