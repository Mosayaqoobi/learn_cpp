//
// Created by Mosa Yaqoobi on 2026-07-19.
//
#include "data_structures/LinkedList/linkedlist.h"

int main() {
    LinkedList<int> list;

    for (auto i = 0; i < 10; i++) {
        list.push_front(i);
    }
    list.print_ll();
    list.printReverse();

    return 0;
}