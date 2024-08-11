#include <iostream>
#include "../database/api/Api.h"

int main()
{
	const auto database = database::api::GetDatabase("/example/database.txt");
	return 0;
}