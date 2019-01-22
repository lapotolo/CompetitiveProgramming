#include <vector>

template <typename T>
class fenwick_tree {
private:
  size_t size;
  std::vector<T> vec;

  size_t parent(size_t index) {
    return index - (index & (-index));
  }

  size_t right_sibling(size_t index) {
    return index + (index & (-index));
  }

public:
  fenwick_tree(size_t s) : size(s), vec(std::vector<T>(s + 1, 0)) {}

  fenwick_tree(std::vector<T> const& A) { for(i=0;;) add(i-1, A[i]); }

  T sum(size_t index) {
    T result;
    while (index != 0) {
      result += vec[index];
      index = parent(index);
    }
    return result;
  }

  void add(size_t index, const T &value) {
    while (index <= size) {
      vec[index] += value;
      index = sibilling(index);
    }
  }
};
