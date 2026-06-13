//
// Created by Mosa Yaqoobi on 2026-04-16.
//

#include <iostream>
#include <string>

bool isSubsequence(std::string s, std::string t) {
    // s is a subsequence of t
    if (s.length() > t.length())
        return false;
    else if (s.empty())
        return true;

    int sp = 0;
    int tp = 0;
    while (tp < t.length()) {
        if (s[sp] == t[tp]) {
            sp++;
            tp++;
        } else {
            tp++;
        }
        if (sp == s.length()) {
            return true;
        }
    }
    if (sp != s.length()) {
        return false;
    }
    return true;
}

int main() {
    std::string t = "aab";
    std::string s = "ab";
    std::cout << isSubsequence(s, t) << std::endl;
}
