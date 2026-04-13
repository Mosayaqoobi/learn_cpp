//
// Created by Mosa Yaqoobi on 2026-04-12.
//
#include <iostream>
#include <vector>
#include <cassert>


bool increasingTriplet(std::vector<int>& nums) {
        if (nums.size() < 3) return false;
        else {
                auto first = INT_MAX;
                auto second = INT_MAX;
                for (auto& num : nums) {
                        if (num <= first) {
                                first = num;
                        } else if (num <= second) {
                                second = num;
                        } else if (num >= first && num >= second) {
                                return true;
                        }
                }
                return false;
        }
}

int main() {
        std::vector<int> nums{2, 3, 1, 0, 5};
        assert(increasingTriplet(nums) == 1);
}