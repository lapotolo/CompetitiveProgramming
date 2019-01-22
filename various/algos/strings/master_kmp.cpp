#include <iostream>
#include <vector>

using namespace std;

vector<int> compute_failure_function(string const&  P){
    vector<int> pi(P.size()); // all elements initialized to zero by default 0
    int k = 0;
    for (int i = 1; i < P.size(); ++i) {
        while (k > 0 && P[k] != P[i]) k = pi[k - 1];
        if (P[k] == P[i]) ++k;
        pi[i] = k;
    }
    return pi;

}

// counting overlapping
vector<int> kmp(string const& T, string const& P) {
    vector<int> matches(T.size() / P.size(), -1); // starting position in text of a match
    vector<int> pi = compute_failure_function(P);
    int q = 0;
    for (int i = 0; i < T.size(); ++i) {
        while (q > 0 && P[q] != T[i]) q = pi[q - 1];
        if (P[q] == T[i]) ++q;
        if (q == P.size()) matches.push_back(i - q + 1); // i is the endpoint of the full match, k here is |P|, +1 cause we have to return first pos of the match
    }
    return matches;
}


int main() {
    string text = "abbywowoabbyyabkaby";
    string pattern = "abby";
    auto result = kmp(text, pattern);

    // ***** DEBUG PURPOSES **********************
    cout << "matches = [ ";
    for (auto el : result) {
        cout <<el << " ";
    }
    cout << "]" << endl;
    // *******************************************

}