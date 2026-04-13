//
// Created by Mosa Yaqoobi on 2026-04-11.
//
#include <iostream>
#include <vector>
#include <string>
#include <stack>

std::string reverseWords(std::string s) {
    std::stack<std::string> st;
    std::string word {};
    int p = 0;
    while (p < s.length()) {
        if (s[p] == ' ' && word.size() != 0) {
            st.push(word);
            word.clear();
        }
        else if (s[p] != ' ') {
            word.push_back(s[p]);
        }
        p++;
    }
    if (word.size() != 0) {
        st.push(word);
    }
    word.clear();

    while (!st.empty()) {
        word += st.top() + " ";
        st.pop();
    }
    word.pop_back();
    return word;
}

int main() {
    std::string s = "a good   example";

    std::cout << reverseWords(s);
    return 0;
}
