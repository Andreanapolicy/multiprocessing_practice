#pragma once
#include <string>
#include <string_view>

namespace database::domain
{
class ITable
{
public:
	virtual [[nodiscard]] std::string GetByKey(std::string_view key) const = 0;
	virtual void Add(std::string_view value) = 0;
	virtual void Update(size_t index, std::string_view value) = 0;

	virtual ~ITable() = default;
};
} // namespace database::domain