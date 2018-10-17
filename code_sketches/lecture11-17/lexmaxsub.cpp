#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string find_lex_max_substring(string const& input){
    string result;
    char max = input[input.size()-1];
    for(auto it = input.rbegin(); it != input.rend(); ++it){
        if(*it >= max){
            result += *it; // string concat
            max = *it;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}    


int main(){
    string input;
    cin >> input;
    cout << find_lex_max_substring(input);
}