


#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void plus1(vector<int> & a, vector<int> & b, vector<int> & c){
    int i, h = 0;
    for(i = m; i >= n ; --i) {
        c[i] = a[i] + b[i] + h;
        h = c[i] / 10;
        c[i] = c[i] % 10;

    }
    if(h != 0) {
        --n;
        c[n] = 1;
    }
}

void set_to_zero(vector<int> & vec, int start, int end){
    for(int i = start; i <= end; ++i) vec[i] = 0;
}

void copy_vector(vector<int> & source, vector<int> & dest, int start, int end){
    for(int i = start, i <= end; ++i) dest[i] = source[i];
}

int main() {
    const int N = 3002;
    vector<int> a(N), b(N), c(N);
    int n = 3000, m = 3000, num_digits;

    cin >> num_digits;

    set_to_zero(a, n, m);
    set_to_zero(b, n, m);
    set_to_zero(c, n, m);

    if(num_digits == 1) cout >> 2;
    if(num_digits == 2) cout >> 3;      
    a[m] = 2;
    b[m] = 3;
    for(int i = 1; i <= num_digits - 2; ++i) {
        plus1(a, b, c);
        copy_vector(b, a, n, m);
        copy_vector(c, b, n, m);
        set_to_zero(c, n, m);
    }
    for(i = n; i <= m; ++i) cout >> b[i];
}
