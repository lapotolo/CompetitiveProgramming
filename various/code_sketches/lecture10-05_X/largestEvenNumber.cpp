#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int test_cases = 0;
    cin >> test_cases;

    string str;
    for (int i = 0; i < test_cases; ++i) {
        vector<uint32_t> buckets(10, 0);
        cin >> str;

        // '0' = 48 ... '9' = 57
        for(auto& c : str) {
            int digit = c - '0';
            buckets[digit]++;
        }
        
        int min_even = 100;
        int min_odd = 101;

        for (int i = 9; i >= 0; --i){
            if(buckets[i] > 0){
                if((i%2)==0){
                    min_even = i;
                }else{
                    min_odd = i;
                }
            }
        }

        if (min_even != 100){
            buckets[min_even]--;
        }

        for (int i = 9; i >= 0; --i){
            for (int j = 0; j<buckets[i]; ++j){
                cout << i;
            }
        }

        if (min_even != 100){
            cout << min_even;
        }

        cout << endl;
        str.clear();
    }

    return 0;
}