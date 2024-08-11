#include "../../../../catch2/catch.hpp"

#include "../../infrastructure/Serializer.h"

TEST_CASE("Valid database")
{
	GIVEN("file with valid database")
	{
		const auto filename = "/example/full_database.txt";
		WHEN("parse database")
		{
			auto db = database::infrastructure::Serializer::GetDatabase(filename);
			
			THEN("db will be not empty")
			{
				REQUIRE(!db.empty());
				REQUIRE(db.size() == 2);
			}

			THEN("where will be 2 tables")
			{
				auto table1 = db["firstTable"];
				auto table2 = db["secondTable"];

				REQUIRE(table1.size() == 3);
				REQUIRE(table2.size() == 4);
			}
		}
	}
}

TEST_CASE("Empty database")
{
	GIVEN("file with empty database")
	{
		const auto filename = "/example/empty_database.txt";
		WHEN("parse database")
		{
			auto db = database::infrastructure::Serializer::GetDatabase(filename);

			THEN("db will be empty")
			{
				REQUIRE(db.empty());
			}
		}
	}
}

TEST_CASE("Database with empty table")
{
	GIVEN("file with empty database")
	{
		const auto filename = "/example/empty_table_database.txt";
		WHEN("parse database")
		{
			auto db = database::infrastructure::Serializer::GetDatabase(filename);

			THEN("db will be not empty")
			{
				REQUIRE(!db.empty());
				REQUIRE(db.size() == 2);
			}

			THEN("first table is empty")
			{
				auto table = db["empty"];

				REQUIRE(table.empty());
			}

			THEN("second table has values")
			{
				auto table = db["nonempty"];

				REQUIRE(table.size() == 1);
			}
		}
	}
}

TEST_CASE("Invalid database")
{
	GIVEN("file with invalid database")
	{
		const auto filename = "/example/invalid_database.txt";
		WHEN("parse database")
		{
			THEN("will be exception")
			{
				REQUIRE_THROWS(database::infrastructure::Serializer::GetDatabase(filename));
			}
		}
	}
}

TEST_CASE("Non exist database")
{
	GIVEN("non exist file with database")
	{
		const auto filename = "/example/nonexist_database.txt";
		WHEN("parse database")
		{
			THEN("will be exception")
			{
				REQUIRE_THROWS(database::infrastructure::Serializer::GetDatabase(filename));
			}
		}
	}
}