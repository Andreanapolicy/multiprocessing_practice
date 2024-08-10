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

	[[nodiscard]] std::string GetByIndex(size_t index) const override;
	void Add(std::string_view value) override;
	void Update(size_t index, std::string_view value) override;
};
} // namespace database::domain