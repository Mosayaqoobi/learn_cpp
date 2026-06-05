#include <iostream>
#include <ostream>
#include <sys/syslimits.h>
//
// Created by Mosa Yaqoobi on 2026-04-18.
//
int guess(int num) {
    int guess = 1'702'766'719;
    if (num == guess) {
        return 0;
    } if (num > guess) {
        return -1;
    } if (num < guess) {
        return 1;
    }
}

int guessNumber(int n) {
    int low = 0;
    int high = n;
    while (true) {
        int middle = low + (high - low) / 2;
        int ans = guess(middle);
        std::cout <<  high << " " << low << std::endl;
        if (ans == 0) {
            return middle;
        } if (ans == -1) {
            high = middle - 1;
        } if (ans == 1) {
            low = middle + 1;
        }
    }
}

int main() {
    int n = 2'126'753'390;
    int number = guessNumber(n);
    std::cout << number << std::endl;
}