#include <iostream>
#include <vector>

int main(){
  std::ios_base::sync_with_stdio(false);

  int num_of_bars;
  std::cin >> num_of_bars;
  std::vector<int> chocolate_bars(num_of_bars);

  for(int i = 0; i < num_of_bars; i++) std::cin >> chocolate_bars[i];

  int alice_position = 0;
  int bob_position   = num_of_bars - 1;
  int alice_time = 0, bob_time = 0;

  while(alice_position <= bob_position) {
    if(alice_time <= bob_time){
      alice_time += chocolate_bars[alice_position];
      ++alice_position;
    } else {
      bob_time += chocolate_bars[bob_position];
      --bob_position;

    }
  }
  std::cout << alice_position << " " << (num_of_bars - bob_position - 1) << std::endl;
  return 0;
}
