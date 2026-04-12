//
// Created by Mosa Yaqoobi on 2026-04-11.
//
#include <iostream>
#include <ostream>
#include <string>

std::string mergeAlternately(const std::string &word1, const std::string &word2) {
    int p1 = 0;
    int p2 = 0;
    std::string result {};
    result.reserve(word1.size() + word2.size());
    while (p1 < word1.size() && p2 < word2.size()) {
        result.push_back(word1[p1]);
        result.push_back(word2[p2]);
        p1++;
        p2++;
    }
    result.append(word2, p2, word2.size() - p2);
    result.append(word1, p1, word1.size() - p1);
    return result;
}


int main() {
    std::string word1 = "abcd";
    std::string word2 = "pq";

    std::cout << mergeAlternately(word1, word2) << std::endl;
}