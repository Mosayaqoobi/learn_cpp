//
// Created by Mosa Yaqoobi on 2026-04-11.
//
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int64_t product = 1;
        int p = 0;
        std::vector<int> result {};

        while (p < nums.size()) {
                result.push_back(product);
                product *= nums[p];
                p++;
        }
        product = 1;
        p = nums.size() - 1;
        while (p >= 0) {
                result[p] *= product;
                product *= nums[p];
                p--;
        }
        return result;
}
int main() {
        std::vector<int> nums {-1, 1, 0, -3, 3};
        nums = productExceptSelf(nums);

        for (auto& v : nums) {
                std::cout << v << std::endl;
        }
}
