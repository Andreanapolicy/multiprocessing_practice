#pragma once
#include <map>
#include "IDatabase.h"
#include "../table/Table.h"

namespace database::domain
{
using DatabaseData = std::map<std::string, TableData>;

class Database : public IDatabase
{
public:
	explicit Database(const DatabaseData& data);

private:
	class Impl;
	std::unique_ptr<Impl> m_impl;
};
} // namespace database::domain