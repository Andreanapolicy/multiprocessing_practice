#include "DatabaseService.h"
#include "../../infrastructure/Serializer.h"
#include "Database.h"

namespace database::domain
{
std::unique_ptr<IDatabase> DatabaseService::ParseDatabase(std::string_view filename)
{
	auto rawDatabase = infrastructure::Serializer::GetDatabase(filename);

	return std::make_unique<Database>(rawDatabase);
}
} // namespace database::domain
