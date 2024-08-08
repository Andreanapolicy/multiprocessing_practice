#include "ThreadPool.h"
#include <iostream>
#include <mutex>

std::mutex g_cout_mutex;

void SayHello()
{
	g_cout_mutex.lock();
	std::cout << "Hello" << std::endl;
	g_cout_mutex.unlock();
}

int main()
{
	thread::ThreadPool threadPool{ 100, SayHello };
	return 0;
}