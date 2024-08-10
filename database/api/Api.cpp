#include "Api.h"
#include "../domain/database/Database.h"
#include "../domain/database/DatabaseService.h"

namespace database::api
{
std::unique_ptr<domain::IDatabase> GetDatabase(std::string_view filename)
{
	return domain::DatabaseService::ParseDatabase(filename);
}

} // namespace database::api