//
// Created by Mosa Yaqoobi on 2026-03-22.
//

#ifndef LEARN_CPP_LINKEDLIST_H
#define LEARN_CPP_LINKEDLIST_H

#include <cstddef>
#include <print>
#include <stdexcept>

template <typename T>
class LinkedList {

    class Node {
        T data;
        Node* next;

      public:
        Node(T value) : data {value}, next {nullptr} {}
    };

    Node* head {nullptr};
    std::size_t size_ {};

  public:
    LinkedList() = default;

    ~LinkedList() = default;

    LinkedList(LinkedList&& other) noexcept : head(other.head), size_(other.size_) {
        other.head = nullptr;
        other.size_ = 0;
    }

    T& front() {
        if (size_ == 0) {
            throw std::logic_error("Nothing in the front \n");
        }
        return head->data;
    }

    const T& front() const {
        if (empty()) {
            throw std::logic_error("Nothing in the front \n");
        }
        return head->data;
    }

    bool empty() const noexcept {
        return size_ == 0;
    }

    std::size_t size() const noexcept {
        return size_;
    }

    void push_front(const T& data) {
        Node* node {data};
        node->next = head;
        head = node;
        size_++;
    }

    void pop_front() {
        if (empty()) {
            throw std::logic_error("Nothing in the front \n");
        }
        Node* node {head};
        head = node->next;
        node->next = nullptr;
        delete node;
        size_--;
    }

    void clear() noexcept {
        while (head) {
            pop_front();
        }
    }

    T& back() {
        if (empty()) {
            throw std::logic_error("list is empty \n");
        }
        Node* temp {head};
        while (temp->next) {
            temp = temp->next;
        }
        return temp->data;
    }

    void print() const noexcept {
        if (empty()) {
            std::print("[] \n");
        } else {

            const Node* temp {head};
            std::print("[ ");
            while (temp) {
                if (temp->next) {
                    std::print("{}, ", temp->data);
                } else {
                    std::print("{}", temp->data);
                }
                temp = temp->next;
            }
            std::print(" ] \n");
        }
    }
};

#endif
