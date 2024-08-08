#pragma once
#include <concepts>
#include <thread>
#include <vector>

namespace thread
{
template <class F, class... Args>
concept regular_callable = std::invocable<F, Args...>;

template <regular_callable T>
class ThreadPool
{
public:
	ThreadPool(size_t amount, T&& function)
		: m_amount{ amount }
	{
		for (auto i = 0; i < m_amount; i++)
		{
			m_threadPool.emplace_back(function);
		}
	}

	~ThreadPool()
	{
		std::ranges::for_each(m_threadPool, [](auto& thread) { thread.join(); });
	}

private:
	size_t m_amount = 0;
	std::vector<std::thread> m_threadPool;
};

} // namespace thread