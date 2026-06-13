#include "sort.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string_view>
#include <vector>

std::string format_time(long long total_us) {
    if (total_us >= 1'000'000) {
        auto seconds = total_us / 1'000'000;
        auto ms = (total_us % 1'000'000) / 1000;
        return std::to_string(seconds) + "s " + std::to_string(ms) + "ms";
    }

    if (total_us >= 1000) {
        auto ms = total_us / 1000;
        auto us = total_us % 1000;
        return std::to_string(ms) + "ms " + std::to_string(us) + "us";
    }

    return std::to_string(total_us) + "us";
}

template <typename T, typename SortFunc>
void time_sort(std::string_view name, const std::vector<T>& original, SortFunc sort_func) {
    constexpr int trials {5};

    long long total_us {0};
    bool sorted_correctly {true};

    for (int i {0}; i < trials; ++i) {
        auto nums = original;

        auto start = std::chrono::steady_clock::now();

        sort_func(nums);

        auto end = std::chrono::steady_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        total_us += duration.count();

        if (!std::is_sorted(nums.begin(), nums.end())) {
            sorted_correctly = false;
        }
    }

    auto average_us = total_us / trials;

    std::cout << name << ": " << format_time(average_us) << " average over " << trials << " runs";

    if (sorted_correctly) {
        std::cout << " | sorted correctly\n";
    } else {
        std::cout << " | NOT sorted correctly\n";
    }
}

int main() {
    std::size_t size {10000};
    std::vector<uint32_t> original(size);

    std::mt19937 rng(100000000);
    std::uniform_int_distribution<uint32_t> dist(1, 1'000'000'000);

    for (auto& val : original) {
        val = dist(rng);
    }

    // time_sort("bubble_sort", original, [](std::vector<uint32_t>& nums) {
    //     Sort::bubble_sort(nums);
    // });

    time_sort("insertion_sort", original,
              [](std::vector<uint32_t>& nums) { Sort::insertion_sort(nums, 0, nums.size()); });

    // time_sort("selection_sort", original, [](std::vector<uint32_t>& nums) {
    //     Sort::selection_sort(nums);
    // });

    time_sort("merge_sort", original, [](std::vector<uint32_t>& nums) { Sort::merge_sort(nums); });

    time_sort("quicksort", original, [](std::vector<uint32_t>& nums) {
        Sort::quicksort(nums, std::size_t {0}, nums.size());
    });

    time_sort("radix sort", original, [](std::vector<uint32_t>& nums) { Sort::radixsort(nums); });

    time_sort("sort", original, [](std::vector<uint32_t>& nums) { std::ranges::sort(nums); });
}
