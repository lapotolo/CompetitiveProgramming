#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
    int xs[5];
    int x = 0;
    short x_short = 0;
    uint8_t uin = 12;
    cout << uin << endl;
    uint32_t y = 0;
    size_t z = 0;
    double a = 0.345675454;
    char c = ' ';
    string s = "qwertyuiopasdfghjklzxcvbnm";
    long long lli = 1234567890876;
    long v = 0.12121211;
    int64_t i64 = 1;

    cout << "[byte] int[] size = " << sizeof(xs) << endl;
    cout << "[byte] int size = " << sizeof(x) << endl;
    cout << "[byte] short size = " << sizeof(x_short) << endl;
    cout << "[byte] uint32_t size = " << sizeof(y) << endl;
    cout << "[byte] size_t size = " << sizeof(z) << endl;
    cout << "[byte] double size = " << sizeof(a) << endl;
    cout << "[byte] char size = " << sizeof(c) << endl;
    cout << "[byte] string size = " << sizeof(s) << endl;
    cout << "[byte] uint8_t size = " << sizeof(uin) << endl;
    cout << "[byte] long long size = " << sizeof(lli) << endl;
    cout << "[byte] long size = " << sizeof(v) << endl;
    cout << "[byte] int64_t size = " << sizeof(i64) << endl;
}
