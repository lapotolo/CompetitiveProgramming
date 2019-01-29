#include <iostream>
#include <vector>

using namespace std;

int kmp(const string &T, const string &P) {
  if (P.empty()) return 0;

  vector<int> pi(P.size(), 0);
  for (int i = 1, k = 0; i < P.size(); ++i) {
    while (k && P[k] != P[i]) k = pi[k - 1];
    if (P[k] == P[i]) ++k;
    pi[i] = k;
  }

  for (int i = 0, k = 0; i < T.size(); ++i) {
    while (k && P[k] != T[i]) k = pi[k - 1];
    if (P[k] == T[i]) ++k;
    if (k == P.size()) return i - k + 1;
  }

  return -1;
}

vector<int> compute_pref_suff_array(string const& pattern){
    auto m = pattern.size();
    int k = 0;

    vector<int> pi(m+1);
    pi[1] = 0;
    for(int q = 1; q < m; ++q){
        while(k > 0 && pattern[k] != pattern[q]) k = pi[k];
        if(pattern[k] == pattern[q]) k++;
        pi[q + 1] = k;
    }
    return pi;
}

vector<int> kmp_matcher(string const& text, string const& pattern){
    vector<int> matches(text.size() / pattern.size()); // starting position in text of a match
    vector<int> pi = compute_pref_suff_array(pattern);
    int q = 0;
    for (int i=0; i<pattern.size(); ++i) {
        while (q>0 && text[q] != pattern[i]) q = pi[q];
        if (text[q] == pattern[i]) q++;
    }
}
int main() {
  string text = "labcdlapoab"; // kmp should return [1,10]
  string pattern = "ab";
  // string pattern = "ababaca";
  auto result = compute_pref_suff_array(s);
  // cout << result[0] << " ";
  cout << result[1] << " ";
  cout << result[2] << " ";
  cout << result[3] << " ";
  cout << result[4] << " ";
  cout << result[5] << " ";
  cout << result[6] << " ";
  cout << result[7] << " ";
  cout << endl;
  result.clear();
  text.clear();
}
