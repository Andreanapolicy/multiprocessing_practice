#pragma once
#include <memory>
#include "IDatabase.h"

namespace database::domain
{
class DatabaseService
{
public:
	[[nodiscard]] static std::unique_ptr<IDatabase> ParseDatabase(std::string_view filename);
};
} // namespace database::domain