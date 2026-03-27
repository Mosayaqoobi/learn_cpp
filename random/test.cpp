//
// Created by Mosa Yaqoobi on 2026-03-26.
//

#include <iostream>
#include <string>
volatile size_t sink = 0;

void byValue(std::string s) {
    sink += s.length();
}

void byReference(const std::string& s) {
    sink += s.length();
}

int main() {
    const std::string text(100000, 'A');
    const int iterations = 1'000'000;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        byValue(text);
    auto end = std::chrono::high_resolution_clock::now();
    auto byValueTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "\n\n";

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        byReference(text);
    end = std::chrono::high_resolution_clock::now();
    auto byRefTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "\n\n";
    std::cout << "By value:     " << byValueTime.count() << " ms\n";
    std::cout << "By reference: " << byRefTime.count() << " ms\n";

    return 0;
}
