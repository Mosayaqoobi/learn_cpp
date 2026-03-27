//
// Created by Mosa Yaqoobi on 2026-03-26.
//

#ifndef LEARN_CPP_STACK_H
#define LEARN_CPP_STACK_H

#include <array>
#include <cstddef>
#include <iosfwd>
#include <stdexcept>
#include <utility>

template <class T, std::size_t N>
class FixedStack {
    std::array<T, N> array;
    std::size_t m_size {};

  public:
    explicit FixedStack() = default;

    [[nodiscard]]
    std::size_t size() const noexcept {
        return m_size;
    }

    [[nodiscard]]
    bool empty() const noexcept {
        return (m_size == 0);
    }

    [[nodiscard]]
    bool full() const noexcept {
        return (m_size == N);
    }

    [[nodiscard]]
    static std::size_t capacity() noexcept {
        return N;
    }

    bool operator==(const FixedStack& obj) const noexcept {
        if (m_size != obj.m_size) {
            return false;
        }
        for (std::size_t i {0}; i < obj.m_size; i++) {
            if (array[i] != obj.array[i]) {
                return false;
            }
        }
        return true;
    }

    void push(const T&& val) {
        if (full()) {
            throw std::length_error("Stack is full\n");
        }
        array[m_size++] = val;
    }

    void push(T& val) {
        if (full()) {
            throw std::length_error("Stack is full\n");
        }
        array[m_size] = std::move(val);
        m_size++;
    }

    void pop() {
        if (empty()) {
            throw std::length_error("Stack is empty\n");
        }
        m_size--;
    }

    const T& top() const {
        if (empty()) {
            throw std::length_error("Stack is empty\n");
        }
        return array[m_size - 1];
    }

    void clear() noexcept {
        m_size = 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const FixedStack& obj) {
        for (std::size_t i {0}; i < obj.m_size; i++) {
            os << obj.array[i] << " ";
        }
        return os;
    }
};

#endif // LEARN_CPP_STACK_H
