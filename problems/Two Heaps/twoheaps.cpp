#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);

  int N;
  std::cin >> N;
  N *= 2;
  std::vector<int> input(N);
  for(size_t i = 0; i < N; ++i) std::cin >> input[i];

  std::vector<int> freq(100, 0);
  for(int & two_d : input ) freq[two_d]++;

  std::vector<std::vector<short> > heaps(2, std::vector<short>(100, 0));

  int rr_i = 1; // round robin index
  for(size_t i = 10; i < 100; ++i) {
    if(freq[i] == 1) {
      rr_i ^= 1;
      ++heaps[rr_i][i];
    }
  }

  std::array<int, 2> dim = {0, 0};

  // Split the numbers with freq > 1 among the two heaps
  for(size_t i = 0; i < 100; ++i) {
    if(freq[i] != 1) {
      heaps[0][i] += freq[i] / 2;
      heaps[1][i] += freq[i] / 2;
      if(freq[i] % 2) {
        rr_i ^= 1;
        heaps[rr_i][i]++;
      }
    }
    dim[0] += heaps[0][i] > 0;
    dim[1] += heaps[1][i] > 0;
  }

  std::cout << (dim[0]*dim[1]) << std::endl;
  // Print the assignment among the two heaps
  for(size_t i = 0; i < N; ++i) {
    std::cout << (heaps[0][input[i]] > 0 ? 1 : 2) << " ";
    heaps[(heaps[0][input[i]] > 0 ? 0 : 1) ][input[i]]--;
  }

  std::cout << std::endl;

  return 0;
}
