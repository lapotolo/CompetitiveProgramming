#include <iostream>
#include <string>

using namespace std;

string hello(string& input){
    int pos = 0;
    string s("hello");
    for (int i = 0; i < input.size(); ++i){
        if (input[i] == s[pos]){
             ++pos;
             if (pos == s.size()) return "YES";
        }
    }
    return "NO";
}

int main() {
    string input;
    getline(cin, input);
    cout << hello(input);
}
