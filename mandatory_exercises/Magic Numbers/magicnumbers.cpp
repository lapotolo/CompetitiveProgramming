#include <iostream>
#include <vector>
#include <string>

using namespace std;

string is_it_magic(int input){
    while(input > 0){
        if (input % 1000 == 144) input = (input - 144) / 1000;
        else if (input % 100  == 14) input = (input - 14) / 100;
        else if (input % 10 == 1) input = (input - 1) / 10;
        else return "NO";
    }
    return "YES";
}

int main() {
    int input;
    cin >> input;
    cout << is_it_magic(input) << endl;
}