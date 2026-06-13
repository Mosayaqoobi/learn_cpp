//
// Created by Mosa Yaqoobi on 2026-04-12.
//
#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    if (nums.size() == 1)
        return;
    int p1 = 0; // finds 0's
    int p2 = 0; // finds nums
    while (p2 < nums.size() && p1 < nums.size()) {
        if (nums[p1] == 0 && nums[p2] != 0) {
            if (p1 < p2) {
                std::swap(nums[p1], nums[p2]);
                p1++;
                p2++;
            } else {
                p2++;
            }
        } else if (nums[p2] == 0) {
            p2++;
        } else if (nums[p1] != 0) {
            p1++;
        }
    }
}

int main() {
    std::vector<int> nums {0, 1, 0, 3, 12};
    moveZeroes(nums);

    for (auto& i : nums) {
        std::cout << i << std::endl;
    }
}
