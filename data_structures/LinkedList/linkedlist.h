//
// Created by Mosa Yaqoobi on 2026-03-22.
//

#pragma once

#include <cstddef>
#include <print>
#include <stdexcept>
#include <unordered_set>

template <typename T>
class LinkedList {

    class Node {

      public:
        T data;
        Node* next;
        Node() : data {}, next {nullptr} {}
        Node(const T& value, Node* next_d) : data {value}, next {next_d} {}
        explicit Node(const T& value) : data {value}, next {nullptr} {}
    };

    Node* head {nullptr};
    Node* tail {nullptr};
    std::size_t size_ {};

  public:
    LinkedList() = default;

    ~LinkedList() {
        clear();
    }
    
    LinkedList(LinkedList&& other) noexcept : head(other.head), tail(other.tail), size_(other.size_) {
        other.head = nullptr;
        other.tail = nullptr;
        other.size_ = 0;
    }
    LinkedList& operator=(LinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            size_ = other.size_;
            other.head = other.tail = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    T& front() {
        if (empty()) {
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

    T& back() {
        if (empty()) {
            throw std::logic_error("list is empty \n");
        }
        return tail->data;
    }

    const T& back() const {
        if (empty()) {
            throw std::logic_error("list is empty\n");
        }
        return tail->data;
    }

    [[nodiscard]] bool empty() const noexcept {
        return size_ == 0;
    }

    [[nodiscard]] std::size_t size() const noexcept {
        return size_;
    }

    void push_front(const T& data) {
        Node* node = new Node {data};
        node->next = head;
        head = node;
        if (empty()) {
            tail = node;
        }
        size_++;
    }
    void push_back(const T& data) {
        Node* node = new Node(data, nullptr);

        if (empty()) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        size_++;
    }

    void pop_front() {
        if (empty()) {
            throw std::logic_error("Linked list is empty \n");
        }
        Node* node {head};
        head = node->next;
        delete node;
        size_--;
    }

    void pop_back() {
        if (empty()) {
            throw std::logic_error("Linked list is empty\n");
        }
        Node* node {head};
        if (tail == head) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size_--;
            return;
        }
        while (node->next != tail) {
            node = node->next;
        }
        delete tail;
        node->next = nullptr;
        tail = node;
        size_--;
    }

    void clear() noexcept {

        while (head) {
            Node* node {head->next};
            delete head;
            head = node;
        }
        tail = nullptr;
        size_ = 0;
    }

    void print_ll() const noexcept {
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
    void removeDuplicates() noexcept {
        std::unordered_set<T> seen; //keep track of the seen elements so far
        Node* node {head};
        Node* prev = nullptr;
        while (node) {
            if (seen.contains(node->data)) {
                prev->next = node->next;
                delete node;
                node = prev->next;
                size_--;
            } else {
                seen.insert(node->data);
                prev = node;
                node = node->next;
            }
        }
        tail = prev;
    }
    [[nodiscard]] bool search(const T& value) const noexcept {
        for (Node* node {head}; node; node = node->next) {
            if (node->data == value) {
                return true;
            }
        }
        return false;
    }


};

