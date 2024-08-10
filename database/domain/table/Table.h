#pragma once
#include "ITable.h"
#include <map>

namespace database::domain
{
using TableData = std::map<std::string, std::string>;

class Table final : public ITable
{
public:
	Table(const TableData& data);

	[[nodiscard]] std::string GetByKey(std::string_view key) const override;
	void Add(std::string_view value) override;
	void Update(size_t index, std::string_view value) override;

private:
	TableData m_data;
};
} // namespace database::domain