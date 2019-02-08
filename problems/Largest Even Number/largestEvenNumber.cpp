#include <iostream>
#include <vector>
#include <string>

#define printele(x) std::cout << x << std::endl;
#define printdbg(x) std::cout << #x ": " << x << std::endl;
#define printarr(a, start) for(int i = start; i < a.size(); ++i) {std::cout<<a[i]<<" ";}  std::cout<<" : " #a <<"\n";


int main() {

	int t, digit, min_even;
	std::cin >> t;

	std::string str;
	while(t > 0) { 
		min_even = 10;
		std::vector<int> buckets(11, 0);
		std::cin >> str;
		for(auto & c : str) {
      digit = c - '0';
			if( (digit%2) == 0 && digit < min_even) {
				buckets[min_even]++;
				min_even = digit;	
			}
      else buckets[digit]++;
		}    
		for (int i = 9; i >= 0; --i){
			for (int j = 0; j<buckets[i]; ++j){
        std::cout << i;
			}
		}
		(min_even != 10) ? (std::cout << min_even << std::endl) : (std::cout << std::endl);
    str.clear();
    --t;
		}
		
    return 0;
}