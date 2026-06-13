#include <iostream>
#include <ostream>
#include <vector>

int compress(std::vector<char>& chars) {
    if (chars.size() == 1)
        return 1;
    int count = 1;
    const int totalSize = static_cast<int>(chars.size());
    char currChar = chars[0];
    int i = 1;
    while (i < totalSize) {
        for (const auto& f : chars) {
            std::cout << f;
        }
        if (chars[i] == currChar) {
            count++;
        } else if (chars[i] != currChar) {
            chars.push_back(currChar);
            chars.erase(chars.begin());
            if (count > 1) {
                for (std::string temp {std::to_string(count)}; auto& j : temp) {
                    chars.push_back(j);
                    chars.erase(chars.begin());
                }
            }
            count = 1;
        }
        currChar = chars[i];
        i++;
    }
    chars.push_back(currChar);
    if (count > 1) {
        std::string temp {std::to_string(count)};
        for (auto& i : temp) {
            chars.push_back(i);
        }
    }
    chars.erase(chars.begin(), chars.begin() + totalSize);
    return static_cast<int>(chars.size());
}

int main() {
    std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c', 'c',
                               'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c'};
    int count = compress(chars);
    std::cout << count << std::endl;
    for (auto& i : chars) {
        std::cout << i << std::endl;
    }
}
