//
// Created by Mosa Yaqoobi on 2026-04-19.
//
#include <iostream>
#include <ostream>
#include <vector>

double findMaxAverage(std::vector<int>& nums, int k) {
    if (nums.size() == 1)
        return nums[0];
    double maxWindow = INT_MIN;
    int currentSum = 0;
    for (auto i = 0; i < nums.size(); i++) {
        currentSum += nums[i];
        if (i == k - 1 && currentSum > maxWindow)
            maxWindow = currentSum;
    }
    return maxWindow;
}

int main() {
    std::vector<int> nums {1, 12, -5, -6, 50, 3};
    std::cout << findMaxAverage(nums, 4) << std::endl;
}
