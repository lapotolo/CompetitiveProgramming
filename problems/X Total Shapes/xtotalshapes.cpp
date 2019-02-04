#include <iostream>
#include <vector>

#define WHITE 0
#define GRAY 1
#define BLACK 2

bool is_valid_position( int i, int j, int rows, int columns
                      , std::vector<std::string> const& input)
{
  if(i >= rows or j >= columns or i < 0 or j < 0) return false;
  if(input[i][j] != 'X') return false;
  return true;
}

void DFS( int i, int j, int rows, int columns
        , std::vector<std::vector<short>> & visited
        , std::vector<std::string> const& input)
{
  int next_i, next_j;
  std::vector<short> x_directions({1, -1, 0, 0});
  std::vector<short> y_directions({0, 0, 1, -1});

  visited[i][j] = 1;
  for(int k = 0; k < x_directions.size(); ++k) {
    next_i = i + x_directions[k];
    next_j = j + y_directions[k];
    if(is_valid_position(next_i, next_j, rows, columns, input) and !visited[next_i][next_j]){
      DFS(next_i, next_j, rows, columns, visited, input);
    }
  }
}

int count_cc(std::vector<std::string> const& input){
  int rows = input.size();
  int columns = input[0].size();
  int connected_components = 0;
  std::vector< std::vector<short> > visited(rows, std::vector<short>(columns));

  for(int i = 0; i < rows; ++i){
    for (int j = 0; j < columns; ++j){
      if(input[i][j] == 'X' and !visited[i][j]) {
        DFS(i, j, rows, columns, visited, input);
        connected_components++;
      }
    }
  }
  return connected_components;
}


int main() {
  int test_cases;
  std::cin >> test_cases;

  while (test_cases > 0){
    int N, M;
    std::cin >> N >> M;
    std::vector<std::string> input;
    for(int i = 0; i < N; ++i){
      std::string s;
      std::cin >> s;
      input.push_back(s);
    }
    std::cout << count_cc(input) << std::endl;
    test_cases--;
  }
  return 0;
}
