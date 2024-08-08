#pragma once

namespace database::domain
{
class ITable
{
public:
	virtual [[nodiscard]] std::wstring& GetByIndex(size_t index) = 0;
	virtual void Add(std::wstring_view value) = 0;
	virtual void Update(size_t index, std::wstring_view value) = 0;
};
} // namespace database::domain