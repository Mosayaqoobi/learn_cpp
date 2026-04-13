//
// Created by Mosa Yaqoobi on 2026-04-11.
//

#include <vector>
#include <ranges>
#include <algorithm>
#include <iostream>
#include <ostream>


std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        std::vector<bool> result {};
        result.reserve(candies.size());

        const auto max = *std::ranges::max_element(candies);

        for (const auto& kid : candies) {
                if (kid + extraCandies >= max) {
                        result.push_back(true);
                } else {
                        result.push_back(false);
                }
        }
        return result;
}

int main() {
        std::vector<int> temp{4, 2, 1, 1, 2};
        std::vector<bool> ret {kidsWithCandies(temp, 1)};
        for (auto v : ret) {
                std::cout << v << std::endl;
        }
}
