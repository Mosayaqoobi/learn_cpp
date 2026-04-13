//
// Created by Mosa Yaqoobi on 2026-04-11.
//
#include <vector>
#include <cassert>


bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int p = 0;
        size_t size = flowerbed.size();
        for (int i = 0; i < flowerbed.size(); i++) {
                if (flowerbed[i] == 0 && ((i == 0) || ((i - 1 >= 0) && (flowerbed[i - 1] != 1))) && ((i + 1 == size) || ((i + 1 < size) && (flowerbed[i + 1] != 1)))) {
                        p += 1;
                        flowerbed[i] = 1;
                }
        }
        return p >= n;
}

int main() {
        std::vector<int> flowerbed {1, 0, 0, 0, 1};

        assert(canPlaceFlowers(flowerbed, 2) == false);
}