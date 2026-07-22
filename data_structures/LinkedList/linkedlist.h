//
// Created by Mosa Yaqoobi on 2026-03-22.
//

#pragma once

#include <cstddef>
#include <print>
#include <stdexcept>
#include <unordered_set>
#include <memory>

template <typename T>
class LinkedList {

    class Node {

      public:
        T data;
        std::unique_ptr<Node> next;

        Node() : data {}, next {nullptr} {}
        Node(const T& value, std::unique_ptr<Node> next_d) : data {value}, next {std::move(next_d)} {}
        explicit Node(const T& value) : data {value}, next {nullptr} {}
    };

    std::unique_ptr<Node> head {nullptr};
    std::size_t size_ {};

  public:
    LinkedList() = default;

    ~LinkedList() {
        clear();
    }
    
    LinkedList(LinkedList&& other) noexcept : head(std::move(other.head)), size_(other.size_) {
        other.head = nullptr;
        other.size_ = 0;
    }
    LinkedList& operator=(LinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = std::move(other.head);
            size_ = other.size_;
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

    const T& back() const {
        if (empty()) {
            throw std::logic_error("list is empty\n");
        }
        Node* node {head.get()};
        while (node->next != nullptr) {
            node = node->next.get();
        }
        return node->data;
    }

    [[nodiscard]] bool empty() const noexcept {
        return size_ == 0;
    }

    [[nodiscard]] std::size_t size() const noexcept {
        return size_;
    }

    void push_front(const T& data) {
        auto node = std::make_unique<Node>(data);
        node->next = std::move(head);
        head = std::move(node);
        size_++;
    }
    void push_back(const T& data) {
        auto node = std::make_unique<Node>(data, nullptr);

        if (empty()) {
            head = std::move(node);
        } else {
            Node* temp {head.get()};
            while (temp->next.get() != nullptr) {
                temp = temp->next.get();
            }
            temp->next = std::move(node);
        }
        size_++;
    }

    void pop_front() {
        if (empty()) {
            throw std::logic_error("Linked list is empty \n");
        }
        head = std::move(head->next);
        size_--;
    }

    void pop_back() {
        if (empty()) {
            throw std::logic_error("Linked list is empty\n");
        } else if (head->next == nullptr) {
            head = nullptr;
            size_ = 0;
        } else {
            Node* node {head.get()};
            Node* prev {nullptr};
            while (node->next != nullptr) {
                prev = node;
                node = node->next.get();
            }
            prev->next.reset();
            size_--;
        }
    }

    void clear() noexcept {

        while (head) {
            head = std::move(head->next);
        }
        size_ = 0;
    }

    void print_ll() const noexcept {
        if (empty()) {
            std::print("[] \n");
        } else {

            const Node* temp {head.get()};
            std::print("[ ");
            while (temp) {
                if (temp->next) {
                    std::print("{}, ", temp->data);
                } else {
                    std::print("{}", temp->data);
                }
                temp = temp->next.get();
            }
            std::print(" ] \n");
        }
    }
    void removeDuplicates() {
        std::unordered_set<T> seen; //keep track of the seen elements so far
        Node* node {head.get()};
        Node* prev = nullptr;
        while (node) {
            if (seen.contains(node->data)) {
                prev->next = std::move(node->next);
                node = prev->next.get();
                size_--;
            } else {
                seen.insert(node->data);
                prev = node;
                node = node->next.get();
            }
        }
    }
    [[nodiscard]] bool search(const T& value) const noexcept {
        for (Node* node {head.get()}; node; node = node->next.get()) {
            if (node->data == value) {
                return true;
            }
        }
        return false;
    }


};

