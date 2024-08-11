#include "../../../../../catch2/catch.hpp"

#include "../../../domain/database/Database.h"

using namespace database::domain;

namespace
{
TableData GetSimpleTable()
{
	TableData data;
	data.emplace("key1", "value1");
	data.emplace("key2", "value2");
	data.emplace("key3", "value3");

	return data;
}
}

TEST_CASE("Empty database")
{
	GIVEN("empty database")
	{
		DatabaseData data;

		Database db(data);

		WHEN("call getting table")
		{
			THEN("will be exception")
			{
				REQUIRE_THROWS(db.GetTable("nonexist"));
			}
		}
	}
}

TEST_CASE("Nonempty database")
{
	GIVEN("nonEmpty database")
	{
		DatabaseData data;
		data.emplace("table", GetSimpleTable());

		Database db(data);

		WHEN("call getting existing table")
		{
			auto table = db.GetTable("table");

			THEN("table is full and its possible to get data")
			{
				REQUIRE(table.GetByKey("key1") == "value1");
			}
		}

		WHEN("call getting non existing table")
		{
			THEN("will be exception")
			{
				REQUIRE_THROWS(db.GetTable("nonexist"));
			}
		}
	}
}