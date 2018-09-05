#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

void print_binary_reprensentation(int const& x){
    for (int i = 31; i >= 0; i--) {
        if (x&(1<<i)) cout << "1";
        else cout << "0";
    }
    cout << endl;
}

// TESTED. IF k >= 32 circular behaviour
// counting from zero
void kth_bit_to_one(int & x, int k){ x = x | (1<<k); }
void kth_bit_to_zero(int & x, int k){ x = x & ~(1<<k); }
void flip_kth_bit(int & x, int k){ x = x ^ (1<<k); }
void flip_after_last_one(int & x){x = x | (x-1);}
int get_least_significant_one(int const& x){return x & -x;}
void set_least_sig_bit_to_zero(int & x){kth_bit_to_zero(x, log2(get_least_significant_one(x)));}
// **** not working as intended **************************
void last_bit_to_one(int & x){ x = x & (x-1); }
bool is_power_of_two(int x){ return (x & (x-1) == 0); }
bool is_in_set(int set_i, int element_index) {return set_i & (1<<element_index);}
// *******************************************************

// SET IMPLEMENTATION

// print the indexes of bit set to one
void print_elements_in_set(int x){
    for (int i = 0; i < 32; i++) {
        if (x&(1<<i)) cout << i << " ";
    }
}

// just set the the kth bit to one
void add_element(int & set_i, int element){ set_i = set_i | (1<<element); }

// the number of elements in set_i is equal to the number of bit set to one
int get_set_size(int const& set_i){return __builtin_popcount(set_i);}

// floor of log2(x) 
int my_log2(int const& x){
    return sizeof(int)*(1<<3) - 1 - __builtin_clz(x);
}

int next_pow_of_two(int const& x){
    int offset = sizeof(x)*(1<<3)-__builtin_clz(x);
    return 1<<offset;
}

int preceding_pow_of_two(int const& x){
    return 1<<my_log2(x);
}

// k = 31 ... 0
int main() {

    int y = 0;
    int x = 1024;
    cout << ("starting from = ");
    print_binary_reprensentation(x);

    kth_bit_to_one(x,11);
    kth_bit_to_one(x,12);
    kth_bit_to_one(x,17);
    kth_bit_to_one(x,30);
    kth_bit_to_one(x,29);
    kth_bit_to_zero(x,30);
    cout << "after some set to one =\n";
    print_binary_reprensentation(x);
    // kth_bit_to_zero(x, log2(get_least_significant_one(x)));
    set_least_sig_bit_to_zero(x);
    cout << "I want to set least sig bit to zero =\n";
    print_binary_reprensentation(x);

    cout << "is in set 30 ? " << is_in_set(x,29) << endl; 




    cout << "__CHAR_BIT__ = "<< __CHAR_BIT__ << endl;
    int l = 3;
    cout <<"my_log2 (" << l <<") = " << my_log2(l) << endl;
    cout <<"log2(" << l <<") = " << log2(l) << endl;

    int pp = 64;
    cout << preceding_pow_of_two(pp) << endl;
    cout <<"preceding_pow_of_two of (" << pp <<") = " << preceding_pow_of_two(pp) << endl;

    // the number of zeros before the first one
    __builtin_clz(x);
    // the number of zeros at the end of the number (count tail zero)
    __builtin_ctz(x);
    // the number of ones in the number
    __builtin_popcount(x);
    //
    __builtin_parity(x);

}