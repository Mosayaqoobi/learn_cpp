


#include <iostream>
#include <vector>

int maxArea(std::vector<int>& height) {
    int max = 0;
    int p1 = 0;
    int p2 = height.size() - 1;

    while (p1 < p2) {
        std::cout << p2 << " " << p1 << " " << max << std::endl;
        if ((std::min(height[p1], height[p2]) * (p2 - p1)) > max) {
            max = (std::min(height[p1], height[p2]) * (p2 - p1));
        } else if (height[p1] < height[p2]) {
            p1++;
        } else if (height[p1] > height[p2]) {
            p2--;
        } else {
            p2--;
            p1++;
        }
    }
    return max;
}

int main() {
    std::vector<int> h {1, 0, 0, 0, 4, 0, 6};
    std::cout << maxArea(h) << std::endl;
}
