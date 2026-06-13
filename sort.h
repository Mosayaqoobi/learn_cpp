#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

namespace Sort {
    template <typename T>
    void bubble_sort(std::vector<T>& nums) {
        bool sorted {true}; //if no swaps in inner loop, then break early

        for (auto i {0u}; i < nums.size(); ++i) {
            for (auto j {0u}; j < nums.size() - 1 - i; ++j) {
                if (nums[j] > nums[j + 1]) {
                    std::swap(nums[j], nums[j + 1]);
                    sorted = false;
                }
            }

            if (sorted) {
                break;
            }
            sorted = true;
        }
    }

    template < typename T >
    void insertion_sort(std::vector<T>& nums, auto left, auto right) {

        for (auto i {left + 1}; i < right; ++i) {
            auto key = nums[i];
            auto j = i;

            while (j > left && nums[j - 1] > key) {
                nums[j] = nums[j - 1];
                --j;
            }
            nums[j] = key;
        }
    }

    template < typename T>
    void selection_sort(std::vector<T>& nums) {
        for (auto i {0u}; i < nums.size(); ++i) {
            auto it = std::min_element(nums.begin() + i, nums.end());
            auto index = std::distance(nums.begin(), it);

            if (index != i) {
                std::swap(nums[i], nums[index]);
            }
        }
    }

    template < typename T>
    void mergee(std::vector<T>& nums, std::vector<T>& temp, auto left, auto mid, auto right) {
        auto p {left};
        auto q {mid};
        auto k {0};

        while (p < mid && q < right) {
            if (nums[p] <= nums[q]) {
                temp[k] = nums[p];
                ++p;
                ++k;
            }
            else {
                temp[k] = nums[q];
                ++q;
                ++k;
            }
        }
        std::copy(nums.begin() + p, nums.begin() + mid, temp.begin() + k);
        k += (mid - p);
        std::copy(nums.begin() + q, nums.begin() + right, temp.begin() + k);
        k += (right - q);

        std::move(temp.begin(), temp.begin() + k, nums.begin() + left);
    }

    template < typename T>
    void merge_sort_impl(std::vector<T>& nums, std::vector<T>& temp, auto left, auto right) {
         if (right - left <= 32) {
            insertion_sort(nums, left, right);
            return;
        }

        auto mid = left + (right - left) / 2;
        merge_sort_impl(nums, temp, left, mid);
        merge_sort_impl(nums, temp, mid, right);
        if (nums[mid - 1] <= nums[mid]) {
            return;
        }
        mergee(nums, temp, left, mid, right);
    }

    template < typename T >
    void merge_sort(std::vector<T>& nums) {
        std::vector<T> v(nums.size());
        merge_sort_impl(nums, v, 0, nums.size());
    }

    template < typename T>
    std::size_t partitionn(std::vector<T>& nums, auto left, auto right) {
        auto a {nums[left]};
        auto b {nums[left + (right - left) / 2]};
        auto c {nums[right - 1]};
        auto pivot{0};

        if ((a <= b && b <= c) || (a <= b && b <= a)) {
            pivot = b;
        }

        if ((b <= a && a <= c) || (c <= a && a <= b)) {
            pivot = a;
        }
        pivot = c;

        auto p1{left};
        auto p2{right - 1};

        while (true) {
            while (nums[p1] < pivot) {
                ++p1;
            } while (nums[p2] > pivot) {
                --p2;
            } if (p1 >= p2) {
                return p1;
            }
            std::swap(nums[p2], nums[p1]);
            ++p1;
            --p2;
        }
    }

    template < typename T >
    void quicksort(std::vector<T>& nums, auto left, auto right) {
        if (right - left <= 1)
            return;

        auto split = partitionn(nums, left, right);

        quicksort(nums, left, split);
        quicksort(nums, split, right);
    }

    void radixsort(std::vector<uint32_t>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        std::vector<uint32_t> temp(nums.size());

        constexpr std::size_t bucket_count {256};
        constexpr std::size_t byte_count {4};

        for (std::size_t pass {0}; pass < byte_count; ++pass) {
            std::array<std::size_t, bucket_count> count {};

            const auto shift = pass * 8;

            for (auto value : nums) {
                auto byte = (value >> shift) & 0xFF;
                ++count[byte];
            }

            std::array<std::size_t, bucket_count> position {};

            std::size_t running_total {0};

            for (std::size_t i {0}; i < bucket_count; ++i) {
                position[i] = running_total;
                running_total += count[i];
            }

            for (auto value : nums) {
                auto byte = (value >> shift) & 0xFF;
                temp[position[byte]] = value;
                ++position[byte];
            }

            nums.swap(temp);
        }

    }




}