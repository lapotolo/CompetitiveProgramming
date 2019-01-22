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

int kmp(string const& B, string const& A) {

    //  
    auto pi = compute_pref_suff_array(A);
    int q = 0, shifts_count=0, temp=0, max_pref=0;

    for (int i=0; i<B.size(); ++i) {

        while (q>0 && A[q] != B[i]) {
            temp = 0;
            q = pi[q];
        }

        if (A[q] == B[i]) {
            ++q;
            ++temp; //count length of current prefix
        }

        if (temp > max_pref) {
            max_pref = temp;
            shifts_count = i-max_pref+1;    //always <= B.size()/2
        }
    }

    return shifts_count;
}

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    string a;
    string b;

    cin >> n;
    cin >> a >> b;

    b += b; //it becomes the text in which we search

    cout << kmp(a, b) << endl;

    return 0;
}
