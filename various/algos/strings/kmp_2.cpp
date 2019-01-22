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

    // ***** DEBUG PURPOSES **********************
    cout << "pi      = [ ";
    for (auto el : pi) {
        cout << el << " ";
    }
    cout << "]"<< endl;
    // *******************************************
    return pi;

}

// counting overlapping
int kmp(int start, string const& T, string const& P) {
    // ***** DEBUG PURPOSES **********************
    cout << "start   = " << start << endl << "text    = [ ";
    for (int j = start; j < T.size() ; ++j) {
        cout << T[j] << " ";

    }
    cout << "]"<< endl;
    cout << "pattern = [ ";
    for (auto el : P) {
        cout <<el << " ";
    }
    cout << "]" << endl;
    // ******************************************
    vector<int> pi = compute_failure_function(P);
    int q = 0;
    for (int i = start; i < T.size(); ++i) {
        while (q > start && P[q] != T[i]) q = pi[q - 1];
        if (P[q] == T[i]) ++q;
        //*********
        

        //**********    
        if (q == P.size()) return(i - q + 1); // i is the endpoint of the full match, k here is |P|, +1 cause we have to return first pos of the match
    }
    return -1;
}


int main() {
    // string text = "abcabcabyabkaby";
    // string pattern = "abkaby";    
    string text = "abbywowoabbyyabkablukgy";
    string pattern = "abby";
    int start = 0; 
    // vector<int> matches(text.size()/pattern.size());
    do{
        int result = kmp(start, text, pattern);
        cout << "Match at: "<< result << "\n\n";
        start =  result + 1; // + pattern.size()
    } while(start + pattern.size() < text.size());
    

    // ***** DEBUG PURPOSES **********************
    // cout << "matches = [ ";
    // for (auto el : matches) {
    //     cout <<el << " ";
    // }
    // cout << "]" << endl;
    // *******************************************

}