/*
d = {}

d[(0,0)] = 0
d[(1,2)] = 1
d[(2,1)] = 2
d[(2,3)] = 3
d[(3,2)] = 4

for (i,j) in d:
    print d[(i,j)], d[(j,i)]
*/

#include <iostream>
#include <map>

typedef std::map<std::pair<int, int>, int> Dict;
typedef Dict::const_iterator It;

int main(){
   Dict d;

   d[std::make_pair(0, 0)] = 0;
   d[std::make_pair(1, 2)] = 1;
   d[std::make_pair(2, 1)] = 2;
   d[std::make_pair(2, 3)] = 3;
   d[std::make_pair(3, 2)] = 4;

   for (auto it = d.begin(); it != d.end(); ++it){
      int i(it -> first.first);
      int j(it -> first.second);
      std::cout <<it->second << ' ' << d[std::make_pair(j, i)] <<'\n';
   }
}