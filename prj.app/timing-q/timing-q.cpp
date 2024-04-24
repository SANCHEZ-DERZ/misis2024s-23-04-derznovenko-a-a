// C++ program to illustrate time point
// and system clock functions
#include <iostream>
#include <chrono>
#include <ctime>
#include <stackarrt/stackarrt.hpp>
#include <vector>

// Function to calculate
// Fibonacci series


int main()
{
	// Using time point and system_clock
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	StackArrT<int> stack;
	std::chrono::duration<double> sum;
	std::vector<std::chrono::duration<long double>> vec_of_time;
	for (int i = 0; i < 10; i++) {
		start = std::chrono::steady_clock::now();
		for (int i = 0; i < 10000; i++) {
			stack.Push(i);
		}
		while (!stack.IsEmpty()) {
			stack.Pop();
		}
		for (int i = 0; i < 10000; i++) {
			stack.Push(i);
		}
		end = std::chrono::steady_clock::now();

		std::chrono::duration<long double> elapsed_seconds = end - start;
		sum += elapsed_seconds;
		vec_of_time.push_back(elapsed_seconds);
	}
	//std::time_t end_time = std::chrono::steady_clock::to_time_t(end);

	for (int i = 0; i < vec_of_time.size(); i++) {
		std::cout << "elapsed time: " << vec_of_time[i].count() << "s\n";
	}
	std::chrono::duration<long double> avg_time = sum / vec_of_time.size();
	std::cout << "avg time: " << avg_time.count();
}
