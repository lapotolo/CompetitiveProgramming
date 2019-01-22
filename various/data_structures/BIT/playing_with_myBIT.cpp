#include "myBIT.hpp"

using namespace std; 


int main(){
    vector<int> A({3,2,-1,5,7,-3,2,1});

    BIT<int> fen(A);
    for (auto el : fen.B) cout << el << " ";
x    cout << endl;
    cout << fen.sum(1) << endl;
    cout << fen.sum(2) << endl;
    cout << fen.sum(3) << endl;
    cout << fen.sum(4) << endl;
    cout << fen.sum(5) << endl;


    return 0;
}
