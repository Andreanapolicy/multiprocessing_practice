#pragma once
#include <string>
#include "../domain/database/IDatabase.h"

namespace database::api
{
[[nodiscard]] domain::IDatabase GetDatabase(std::string_view filename);
void SaveDatabase(domain::IDatabase, std::string_view filename);
} // namespace database::api