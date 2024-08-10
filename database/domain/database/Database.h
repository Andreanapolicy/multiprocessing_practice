#pragma once
#include <map>
#include "IDatabase.h"
#include "../table/Table.h"

namespace database::domain
{
using DatabaseData = std::map<std::string, TableData>;

class Database final : public IDatabase
{
public:
	explicit Database(const DatabaseData& data);
	~Database() override;

	[[nodiscard]] const ITable& GetTable(std::string_view name) const override;
	[[nodiscard]] ITable& GetTable(std::string_view name) override;

	void AddTable(std::string_view name) override;

private:
	class Impl;

	std::unique_ptr<Impl> m_impl;
};
} // namespace database::domain