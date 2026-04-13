//
// Created by Mosa Yaqoobi on 2026-04-11.
//

#include <iostream>
#include <ostream>
#include <string>

bool isVowel(char c) {
        switch (std::tolower(c)) {
                case 'a': case 'e': case 'i': case 'o': case 'u':
                        return true;
                default:
                        return false;
        }
}

std::string reverseVowels(std::string s) {
        int start = 0;
        int end = s.length() - 1;
        while (start < end) {
                if (isVowel(s[start]) && isVowel(s[end])) {
                        std::swap(s[start++], s[end--]);
                } else if (isVowel(s[start]) && !isVowel(s[end])) {
                        end--;
                } else if (!isVowel(s[start]) && isVowel(s[end])) {
                        start++;
                } else {
                        start++;
                        end--;
                }
        }
        return s;
}

int main() {
        std::string s = "IceCreAm";
        std::cout << reverseVowels(s) << std::endl;
}