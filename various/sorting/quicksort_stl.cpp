#include <stdio>
#include <vector>
// #include <>
// #include <>


size_t partition(std::vector<int> const& v, size_t low, size_t r)
{
  size_t pivot = v[high];
  size_t i = low - 1;

  for(int j = i; j <= high-1; ++j)
  {
    if (v[j] <= pivot)
    {
      ++i;
      std::swap(v[i], v[j]);
    }
  }
  swap(v[i+1, v[j]);
  return i+1;
        
}
