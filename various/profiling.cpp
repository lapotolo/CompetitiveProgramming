#include <iostream>
#include <vector>
#include <chrono>


using namespace std;

int main(int argc, char const *argv[]){
    constexpr size_t N = 10000;
    auto array = new int[N][N];

    for (size_t i = 0; i < N; ++i){
        for (size_t j = 0; j < N; ++j){
            array[i][j] = rand();
        }
    }

    auto start = std::chrono::high_resolution_clock::now();

    int sum = 0;

    for (size_t i = 0; i < N; ++i){
        for (size_t j = 0; j < N; ++j){
            sum += array[j][i];
        }
    }

    std::cout << sum << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "elapsed: " << elapsed_time.count() << " [millisec]" << std::endl;
}
