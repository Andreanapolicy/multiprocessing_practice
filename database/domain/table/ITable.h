#pragma once
#include <string>
#include <string_view>

namespace database::domain
{
class ITable
{
public:
	virtual [[nodiscard]] std::string GetByIndex(size_t index) const = 0;
	virtual void Add(std::string_view value) = 0;
	virtual void Update(size_t index, std::string_view value) = 0;
};
} // namespace database::domain