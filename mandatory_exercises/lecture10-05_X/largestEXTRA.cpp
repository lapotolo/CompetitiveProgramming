#include <iostream>
#include <vector>
#include <string>
#include <cstring>   // for memmove

// problem: http://practice.geeksforgeeks.org/problems/largest-even-number/0

// assume digits span a consecutive range, i.e., [min_digit..min_digit + num_digits]
template<typename Digital, typename Digit>
void counting_sort(Digital& a, size_t n, int num_digits, Digit min_digit, bool reverse = false) {

    std::vector<uint64_t> counts(num_digits + 1, 0);
    for (size_t i = 0; i < n; ++i) {
        ++counts[a[i] - min_digit];
    }

    for (uint32_t i = 1; i <= num_digits; ++i) {
        counts[i] += counts[i - 1];
    }

    Digital temp;
    temp.resize(n);

    // could do this with bool tricks
    size_t offset = 0;
    int sign = 1;
    int b = -1;

    if (reverse) {
        offset = n;
        sign = -1;
        b = 0;
    }

    for (size_t i = 0; i < n; ++i) {
        temp[offset + sign * counts[a[i] - min_digit] + b] = std::move(a[i]);
        --counts[a[i] - min_digit];
    }

    std::move(temp.begin(), temp.end(), a.begin());
}

void largest_even_number(std::string& str) {
    // ASCII codes for '0' to '9' span a consecutive range ([48..57])
    bool reverse = true;
    counting_sort<std::string, char>(str, str.size(), 10, '0', reverse);

    // determine the position of the smallest even number (if present)
    uint64_t i = str.size() - 1;
    while (str[i] % 2) {
        if (!i) break;
        --i;
    }

    if (str[i] % 2 == 0) { // could not contain any even number
        char x = str[i];
        // shift left by 1
        memmove(&str[i], &str[i + 1], str.size() - i - 1);
        str.back() = x;
    }
}

int main() {

    int num_test_cases = 0;
    std::cin >> num_test_cases;

    std::string str;
    for (int i = 0; i < num_test_cases; ++i) {
        std::cin >> str;
        largest_even_number(str);
        std::cout << str << std::endl;
        str.clear();
    }

    return 0;
}