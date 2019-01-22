#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <priorityqueue>

#define ALL(c) c.begin(), c.end()
#define TRAVERSE(container, it) for(auto it = container.begin(); it != container.end(); ++it)
#define PRINT(c) for(auto el : c) {cout << el << " ";} cout << endl;
#define PRESENT(container, element) (container.find(element) != container.end()) // for map/set
#define CPRESENT(container, element) (find(all(container),element) != container.end()) // for vectors

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

using namespace std;

template<typename T> void reverse_array_stl_compliant(T *begin, T *end) {
    // We should at first decrement 'end'
    // But only for non-empty range
    if(begin != end) {
        end--;
        if(begin != end) {
            while(true) {
                swap(*begin, *end);
                begin++;
                if(begin == end) break;
                end--;
                if(begin == end) break;
            }
        }
    }
}

template<typename T> void reverse_array(T *first, T *last) {
    if(first != last) {
        while(true) {
            swap(*first, *last);
            first++;
            if(first == last) {
                break;
            }
            last--;
            if(first == last) {
                break;
            }
        }
    }
}

int factorial(int n){
    if( n == 0) return 1;
    return n * factorial(n-1);
}

int main(){
    vector<int> v({1,2,3,4});
    int n = v.size();
    PRINT(v);
    // reverse_array_stl_compliant<int>(&v[0], &v[v.size()-1]);
    for(int c = 1; c <= factorial(n); ++c){
        next_permutation(ALL(v));
        PRINT(v);
    }


    auto pointer1 = &v[0];
    auto pointer2 = v.begin().base();
    cout << "\n\n" << pointer1 << endl << pointer2;

    auto endpointer1 = &v[0] + 4;
    auto endpointer2 = v.end().base() - 1;
    cout << "\n\n" << endpointer1 << endl << endpointer2;
    cout << "\n\n" << *endpointer1 << endl << *endpointer2;

    map<string, int> M;
    M["Top"] = 1;
    M["Coder"] = 2;
    M["SRM"] = 10;

    int x = M["Top"] + M["Coder"];

    if(M.find("SRM") != M.end()) {
        M.erase(M.find("SRM")); // or even M.erase("SRM")
    }

    cout << "\n\n";
    //TRAVERSE(M, it) cout << (*it).second << " " ;

    priority_queue<int> q; // maxheap
    priority_queue<int, vector<int>, greater<int>> qmin; // minheap

    qmin.push(5);
    qmin.push(4);
    qmin.push(3);
    qmin.push(33);

    while (! qmin.empty()){
        cout << qmin.top() << " ";
        qmin.pop();
    }

}