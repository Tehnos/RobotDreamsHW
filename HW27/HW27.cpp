#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

int sum(const std::vector<int>& vec) {
    int total = 0;
    for (int num : vec) {
        total += num;
    }
    return total;
}

void partial_sum(const std::vector<int>& vec, int start, int end, std::atomic<int>& result) {
    int partial = 0;
    for (int i = start; i < end; ++i) {
        partial += vec[i];
    }
    result += partial;
}

int parallel_sum(const std::vector<int>& vec) {
    int num_threads = std::thread::hardware_concurrency();
    int n = vec.size();
    std::atomic<int> result(0);

    std::vector<std::thread> threads;
    int block_size = n / num_threads;

    for (int i = 0; i < num_threads; ++i) {
        int start = i * block_size;
        int end = (i == num_threads - 1) ? n : start + block_size;
        threads.push_back(std::thread(partial_sum, std::ref(vec), start, end, std::ref(result)));
    }

    for (auto& t : threads) {
        t.join();
    }

    return result.load();
}
int parallel_sum2Threads(const std::vector<int>& vec) {
    int num_threads = 2;  
    int n = vec.size();   
    std::atomic<int> result(0); 

    std::vector<std::thread> threads;
    int block_size = n / num_threads;  

  
    for (int i = 0; i < num_threads; ++i) {
        int start = i * block_size;
        int end = (i == num_threads - 1) ? n : start + block_size;  
        threads.push_back(std::thread(partial_sum, std::ref(vec), start, end, std::ref(result)));
    }

  
    for (auto& t : threads) {
        t.join();
    }

    return result.load();
}

int parallel_sum2x(const std::vector<int>& vec) {
    int num_threads =2 * std::thread::hardware_concurrency();
    int n = vec.size();
    std::atomic<int> result(0);

    std::vector<std::thread> threads;
    int block_size = n / num_threads;

    for (int i = 0; i < num_threads; ++i) {
        int start = i * block_size;
        int end = (i == num_threads - 1) ? n : start + block_size;
        threads.push_back(std::thread(partial_sum, std::ref(vec), start, end, std::ref(result)));
    }

    for (auto& t : threads) {
        t.join();
    }

    return result.load();
}

void measure_performance(const std::string& label, int (*func)(const std::vector<int>&), const std::vector<int>& vec, double single_thread_time) {
    auto start = std::chrono::high_resolution_clock::now();
    int result = func(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    double time = duration.count();
    double boost =time/ single_thread_time;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << label << ":" << std::endl;
    std::cout << "  Result: " << result << std::endl;
    std::cout << "  Time: " << time << " seconds" << std::endl;
    std::cout << "  Boost: " << boost << "x" << std::endl<< std::endl;
}
void random(std::vector<int>& vec, int a)
{
    std::srand(std::time(0));

    for (auto& num : vec) {
        num = std::rand() % a + 1;
    }
}

int main() {


    std::vector<int> vec(10000);
    std::vector<int> vec2(10000);
    std::vector<int> vec3(10000);
    std::vector<int> vec4(10000);

    random(vec,100);
    random(vec2,50);
    random(vec3,452);
    random(vec4,1000);

    auto start_single_thread = std::chrono::high_resolution_clock::now();
    int single_thread_result = sum(vec);
    auto end_single_thread = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> single_thread_duration = end_single_thread - start_single_thread;
    double single_thread_time = single_thread_duration.count();

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Single-threaded sum:" << std::endl;
    std::cout << "  Result: " << single_thread_result << std::endl;
    std::cout << "  Time: " << single_thread_time << " seconds" << std::endl<< std::endl;

    measure_performance("Parallel sum (2 threads)", parallel_sum2Threads, vec2, single_thread_time);
    measure_performance("Parallel sum " + std::to_string(std::thread::hardware_concurrency()) + " threads", parallel_sum, vec3, single_thread_time);
    measure_performance("Parallel sum " + std::to_string(2 * std::thread::hardware_concurrency()) + " threads", parallel_sum2x, vec4, single_thread_time);

    
    std::cin.get();


    return 0;
}
