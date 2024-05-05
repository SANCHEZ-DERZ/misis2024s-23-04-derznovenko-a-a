#include <iostream>
#include <chrono>
#include <stackarrt/stackarrt.hpp>
#include <vector>
#include <fstream>



int main() {
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	StackArrT<int> stack;
	std::chrono::duration<double> sum{ 0 };
	std::vector<std::chrono::duration<double>> vec_of_time;
	std::vector<std::chrono::duration<double>> vec_of_avg_time;
	for (int i = 0; i < 100; i++) {
		start = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < 1000000; j++) {
			stack.Push(j);
		}
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		sum += elapsed_seconds;
		vec_of_time.push_back(elapsed_seconds);
	}
	
	/*for (int i = 0; i < vec_of_time.size(); i++) {
		std::cout << "elapsed time: " << vec_of_time[i].count() << "ms\n";
	}*/
	std::chrono::duration<double> avg_time = sum / vec_of_time.size();
	std::cout << "avg time: " << avg_time.count() << "ms" << "\n";
	
}




