//Naive algorithm for the construction of the suffix array of a given string
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string s;
    map<string, int> m;
    cin >> s;
    vector<string> v;
    for(int i = 0; i < s.size(); ++i) {
        string subfix = s.substr(i, s.size()-i);
        cout << "(" << subfix << ", " << i << ")\n";
        m[subfix] = i;
        v.push_back(subfix);
    }
    sort(v.begin(),v.end());
    
    cout << "\nsuffixes = [ ";
    for(int i = 0; i < v.size();i++)
        cout << "(" <<v[i] << ", " << m[v[i]] << ") ";
    cout << "]\n";
    cout << "\nsuffix-array = [ ";
    for(int i = 0; i < v.size();i++)
        cout << m[v[i]] << " ";
    cout << "]\n";
    return 0;
}
