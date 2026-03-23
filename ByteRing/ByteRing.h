//
// Created by Mosa Yaqoobi on 2026-03-22.
//

#ifndef OS_BYTERING_H
#define OS_BYTERING_H

#include <array>
#include <stdexcept>

template <std::size_t Capacity> class ByteRing {
    static_assert(Capacity > 0, "ByteRing: Capacity must be greater than 0");

    std::array<std::uint8_t, Capacity> storage{};
    std::size_t head{};  // index of the oldest byte inserted
    std::size_t count{}; // count of bytes currently within storage

  public:
    ByteRing() = default;

    void push(std::uint8_t byte) {
        if (count < Capacity) { // not full, just insert
            storage[(head + count) % Capacity] = byte;
            count++;
        } else { // full, insert then wrap around head
            storage[head] = byte;
            head = (head + 1) % Capacity;
        }
    }

    [[nodiscard]]
    bool full() const {
        return (count == Capacity);
    }

    [[nodiscard]]
    bool empty() const {
        return (count == 0);
    }

    [[nodiscard]]
    std::size_t size() const {
        return count;
    }

    void clear() {
        count = 0;
        head = 0;
    }

    [[nodiscard]]
    std::uint8_t at(std::size_t i) const {
        if (count == 0 || i >= count) {
            throw std::out_of_range("invalid index");
        }
        return storage[(head + i) % Capacity];
    }
};
#endif // OS_BYTERING_H
