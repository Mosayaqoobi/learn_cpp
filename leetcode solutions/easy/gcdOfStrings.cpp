//
// Created by Mosa Yaqoobi on 2026-04-11.
//
#include <string>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <numeric>
#include <ostream>

std::string gcdOfStrings(std::string str1, std::string str2) {
        if (str1 + str2 == str2 + str1) {
                auto gcd = std::gcd(str1.size(), str2.size());
                return str1.substr(0, gcd);
        } else {
                return "";
        }
}

int main() {
        std::string str1 = "abab";
        std::string str2 = "ababab";
        assert(gcdOfStrings(str1, str2) == "ab");
}
