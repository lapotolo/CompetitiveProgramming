#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <string>


using namespace std;
// vector<bool> generate_sieve(int n){
//     vector<bool> primes(n, true);
//     for (int i = 0; i * i < n; ++i) {
//         primes [i] = true;
    

//     for (int i = 5, t = 2; i < n; i += t, t = 6 - t) {
//         if (primes [i / 3]) {
//             for (int j = i * i, v = t; j < n; j += v * i, v = 6 - v) 
//                 primes [j / 3] = false; 
//         }
//     }
//     return primes;
// }  


typedef map<string, int> dict;

string compare(string& input){
    int pos = 0;
    vector<string> s(3);
    s.emplace_back("1");
    s.emplace_back("14");
    s.emplace_back("144");
    
    while(pos < input.size()){
        if(pos+2 < input.size())
            if(s[2].compare(pos, 3, input) != 0) pos += 3;
        else if(pos+1 < input.size())
            if(s[1].compare(pos, 2, input ) != 0) pos += 2;
        else if(s[0].compare(pos, 1, input) != 0) pos += 1;
        else return "NO";

    }
    return "YES";
}


int main(){

    string s1 = "Marta loves green apples.";
    string s2 = "Green apples are loved by Marta";
    string s3 = "Green apples";

    cout << s2.compare(0, 12, s3) << endl;
    cout << s1.substr(0,5) << endl;
    cout << s2.substr(26, s2.size()-1) << endl; // ???

    return 0;
}