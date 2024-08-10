#pragma once
#include "../domain/database/IDatabase.h"

namespace database::api
{
[[nodiscard]] std::unique_ptr<domain::IDatabase> GetDatabase(std::string_view filename);
void SaveDatabase(domain::IDatabase& database, std::string_view filename);
} // namespace database::api