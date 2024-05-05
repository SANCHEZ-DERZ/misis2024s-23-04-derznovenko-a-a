#include <iostream>
#include <chrono>
#include <stackarrt/stackarrt.hpp>
#include <vector>
#include <iomanip>


template <typename T>
long double Time_of_push(T& stack, int num) {
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	long double sum = 0;
	std::vector<std::chrono::duration<long double>> vec_of_time;
	std::vector<std::chrono::duration<long double>> vec_of_avg_time;
	for (int i = 0; i < 100; i++) {
		start = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < num; j++) {
			stack.Push(j);
		}
		end = std::chrono::high_resolution_clock::now();
		stack.Clear();
		std::chrono::duration<long double> elapsed_seconds = end - start;
		elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		sum += elapsed_seconds.count();
		vec_of_time.push_back(elapsed_seconds);
	}
	long double avg_time = sum / vec_of_time.size();
	return avg_time;
}


int main() {
	StackArrT<int> Stack;
	std::vector<long double> avg_times;
	for (int i = 0; i < 100; i++) {
		long double Time = Time_of_push(Stack, i);
		std::cout << std::fixed << std::setprecision(10);
		std::cout << Time << "\n";
	}
}




