// author : Lapo Toloni
// problem : http://codeforces.com/problemset/problem/6/C?locale=en

#include <iostream>
#include <vector>
#include <algorithm>
#include "myBIT.hpp"

using namespace std;

// int main() {
//     int n, alice_counter=0, bob_counter=0;
//     cin >> n;
//     vector<int> prefix_sum_Alice(n);
//     vector<int> prefix_sum_Bob(n);


//     int duration;
//     for(int i=0; i<n; ++i){
//         cin >> duration;
//         prefix_sum_Alice[i] += duration;
//         prefix_sum_Bob[n-i-1] += duration; 
//     }    
//     for(int i=1; i<n; ++i){
//         prefix_sum_Alice[i] += prefix_sum_Alice[i-1];
//         prefix_sum_Bob[i] += prefix_sum_Bob[i-1]; 
//     }
    

//     for(int i = 0; i <= prefix_sum_Alice[n-1] or alice_counter==n-1-bob_counter; ++i){
//         if(i >= prefix_sum_Alice[alice_counter]) alice_counter++;
//         if(i >= prefix_sum_Bob[bob_counter]) bob_counter++;
//     }
//     cout << alice_counter << " " << bob_counter << endl;


//     return 0;
// }

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

struct chocolate_eater{
    int eaten;
    int wait;
    chocolate_eater() : eaten(0), wait(0){} 
};

int main() {
    chocolate_eater alice();
    chocolate_eater bob();
    int n;
    cin >> n;
    deque<int> choco_bars;
    choco_bars.reserve(n);
    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        chocs.push_back(t);
    }
    while(chocs.size()>0){
        if(alice.wait != 0) alice.wait--;
        if(bob.wait != 0) bob.wait--;
        if(alice.wait==0){
            alice.wait = chocs[0];
            alice.eaten++;
            chocs.pop_front();
        }
        if(bob.wait==0) {
            if(chocs.size()==0)
                break;
            else{
                bob.wait=chocs[chocs.size()-1];
                bob.eaten++;
                chocs.pop_back();
            }
        }
    }
    cout<<alice.eaten<<" "<<bob.eaten<<endl;
    return 0;
}