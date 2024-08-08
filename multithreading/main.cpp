#include "ThreadPool.h"
#include <iostream>

void SayHello()
{
	std::cout << "Hello" << std::endl;
}

int main()
{
	thread::ThreadPool threadPool{ 100, SayHello };
	return 0;
}