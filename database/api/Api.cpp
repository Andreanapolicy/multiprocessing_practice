#include "Api.h"
#include "../domain/database/Database.h"

namespace database::api
{
domain::IDatabase GetDatabase(std::string_view filename)
{
	return database::domain::Database();
}

void SaveDatabase(domain::IDatabase, std::string_view filename)
{
}

} // namespace database::api