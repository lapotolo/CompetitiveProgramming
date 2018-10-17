#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>       /* sqrt */

using namespace std;

class Location{
	int x;
	int y;
	uint32_t population;

	public:
		Location(int x, int y, uint32_t pop)		
			: x(x)		
			, y(y)		
			, population(pop)
		{}
		
		int get_population() const{
			return population;
		}

		double get_distance() const{		
				return sqrt(x*x + y*y);
		}
};

int main(){
  std::ios_base::sync_with_stdio(false);
  
  size_t n_close_locations; 
  cin >> n_close_locations;
  int current_population;
  cin >> current_population;

    
  vector<Location> cities;
  cities.reserve(n_close_locations);
    
  for(size_t i = 0; i < n_close_locations; i++) {
  	int x, y, pop;
    cin >> x  >> y >> pop;
    cities.emplace_back(x, y, pop);
  }    
    
  sort(cities.begin(),
       cities.end(),
       [](Location const& a, Location const& b) {
            return a.get_distance() < b.get_distance();
          }
  );
    
  for(auto & city : cities) {
    current_population += city.get_population();
    if(current_population >= 1000000) {
      cout.precision(8);
      cout << city.get_distance() << endl;
      return 0;
    }
  }
    
  cout << -1 << endl;     
  return 0;
} 