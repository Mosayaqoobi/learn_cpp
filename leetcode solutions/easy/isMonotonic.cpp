//
// Created by Mosa Yaqoobi on 2026-03-31.
//

#include <vector>

bool isMonotonic(std::vector<int>& nums) {
    if (nums.size() == 1) return true;
    bool is_inc = true;
    bool is_dec = true;
    for (auto i = 0; i < nums.size() - 1; i++) {
        if (nums[i] < nums[i + 1]) {
            is_dec = false;
        } else if (nums[i] > nums[i + 1]) {
            is_inc = false;
        }
    }
    return (is_inc || is_dec) ? true : false;
}