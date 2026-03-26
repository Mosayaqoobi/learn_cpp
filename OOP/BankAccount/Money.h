//
// Created by Mosa Yaqoobi on 2026-03-25.
//

#ifndef LEARN_CPP_MONEY_H
#define LEARN_CPP_MONEY_H
#include <compare>
#include <cstdint>
#include <print>

class Money {
    int64_t cents_ {};

  public:
    explicit Money(const int64_t cents) : cents_ {cents} {}

    explicit Money() = default;

    [[nodiscard]] int64_t getMoney() const {
        return cents_;
    }

    Money operator+(const Money& a) const noexcept {
        return Money {cents_ + a.cents_};
    }

    Money& operator+=(const Money& a) noexcept {
        cents_ += a.cents_;
        return *this;
    }

    Money operator-(const Money& a) const noexcept {
        return Money {cents_ - a.cents_};
    }

    Money& operator-=(const Money& a) noexcept {
        cents_ -= a.cents_;
        return *this;
    }

    bool operator==(const Money&) const noexcept = default;
    auto operator<=>(const Money&) const noexcept = default;
};

#endif // LEARN_CPP_MONEY_H
