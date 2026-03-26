//
// Created by Mosa Yaqoobi on 2026-03-25.
//

#ifndef LEARN_CPP_TRANSACTION_H
#define LEARN_CPP_TRANSACTION_H

#include "Money.h"
#include <string>
#include <utility>

class Transaction {
    Money amount_ {};
    std::string memo_ {};
    static inline int64_t next_id_ {0};
    int64_t id_ {};

  public:
    Transaction(Money amount, std::string memo) : amount_ {amount}, memo_ {std::move(memo)} {
        id_ = ++next_id_;
    };

    [[nodiscard]] const Money& amount() const noexcept {
        return amount_;
    }

    [[nodiscard]] const std::string& memo() const noexcept {
        return memo_;
    }

    [[nodiscard]] const int64_t id() const noexcept {
        return id_;
    }
};

#endif // LEARN_CPP_TRANSACTION_H
