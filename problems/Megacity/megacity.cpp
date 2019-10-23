#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
		
  int get_population() const { return population; }
  
  double get_distance() const { return sqrt(x*x + y*y); }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  
  size_t n_close_locations; 
  std::cin >> n_close_locations;
  int current_population;
  std::cin >> current_population;

    
  std::vector<Location> cities;
  cities.reserve(n_close_locations);
    
  for(size_t i = 0; i < n_close_locations; i++) {
    int x, y, pop;
    std::cin >> x  >> y >> pop;
    cities.emplace_back(x, y, pop);
  }    
  
  auto cities_cmp = [](Location const& a, Location const& b) -> bool
    {
      return a.get_distance() < b.get_distance();
    };
  
  std::sort(cities.begin(), cities.end(), cities_cmp);
  
  for(auto & city : cities) {
    current_population += city.get_population();
    if(current_population >= 1000000) {
      std::cout.precision(8);
      std::cout << city.get_distance() << std::endl;
      return 0;
    }
  }
    
  std::cout << -1 << std::endl;     
  return 0;
} 
