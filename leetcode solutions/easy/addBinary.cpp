#include <string>
#include <algorithm>

std::string addBinary(std::string a, std::string b) {
    int carry = 0;
    int p1 = a.size() - 1;
    int p2 = b.size() - 1;
    std::string s {};


    while (p1 >= 0 || p2 >= 0 || carry) {
        int sum = carry;
        if (p1 >= 0) {
            sum += a[p1] - '0';
        }
        if (p2 >= 0) {
            sum += b[p2] - '0';
        }
        p1--;
        p2--;
        s += (sum % 2) + '0';
        carry = sum / 2;
    }
    std::reverse(s.begin(), s.end());
    return s;
}