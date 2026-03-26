//
// Created by Mosa Yaqoobi on 2026-03-22.
// test the ghetto linkedlist implementation

#include "linkedlist.h"
#include <print>

int main() {
    try {
        LinkedList<int> list;
        std::print("Initially: empty={}, size={}\n", list.empty(), list.size());
        try {
            (void)list.front();
        } catch (const std::exception& e) {
            std::print("front() on empty threw {}\n", e.what());
        }
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);

        std::print("After pushes: empty={}, size={}\n", list.empty(), list.size());
        list.print();
        std::print(" front()={}, back()={}\n", list.front(), list.back());
        list.pop_front();
        std::print("After pop_front: size={}\n", list.size());
        list.print();
        std::print(" front()={}, back()={}\n", list.front(), list.back());
        list.clear();
        std::print("After clear: empty={}, size={}\n", list.empty(), list.size());
        list.print();

        list.pop_front();
    } catch (const std::exception& e) {
        std::print("Unhandled exception: {}\n", e.what());
        return 1;
    }
    return 0;
}
