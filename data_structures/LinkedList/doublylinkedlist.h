//
// Created by Mosa Yaqoobi on 2026-03-24.
//

#ifndef LEARN_CPP_DOUBLYLINKEDLIST_H
#define LEARN_CPP_DOUBLYLINKEDLIST_H

#include <cstddef>
#include <stdexcept>
#include <string_view>
inline constexpr std::logic_error empty_list {"Nothing to look at, no nodes available \n"};

template <typename T>
class DoublyLinkedList {
    struct Node {
        T data {};
        Node* next {nullptr};
        Node* prev {nullptr};
    };

    Node* head {nullptr};
    Node* tail {nullptr};
    std::size_t size_ {};

  public:
    DoublyLinkedList() = default;

    ~DoublyLinkedList() noexcept {
        clear();
    }

    DoublyLinkedList(DoublyLinkedList&& other) noexcept
        : head(other.head), tail(other.tail), size_(other.size_) {
        other.head = nullptr;
        other.tail = nullptr;
        other.size_ = 0;
    }

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    std::size_t size() const noexcept {
        return size_;
    }

    bool empty() const noexcept {
        return (size() == 0);
    }

    T& front() {
        if (empty()) {
            throw std::logic_error(empty_list);
        }
        return head->data;
    }

    const T& front() const {
        if (empty()) {
            throw std::logic_error(empty_list);
        }
        return head->data;
    }

    T& back() {
        if (empty()) {
            throw std::logic_error(empty_list);
        }
        return tail->data;
    }

    const T& back() const {
        if (empty()) {
            throw std::logic_error(empty_list);
        }
        return tail->data;
    }

    void clear() noexcept {
        Node* curr {head};
        while (curr) {
            const Node* temp {curr->next};
            delete curr;
            curr = temp;
        }
        head = nullptr;
        tail = nullptr;
        size_ = 0;
    }

    void push_front(const T& value) {
        Node* const node = new Node();
        node->data = value;

        if (empty()) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size_++;
    }

    void push_back(const T& value) {
        Node* const node = new Node();
        node->data = value;
        if (empty()) {
            tail = node;
            head = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        size_++;
    }

    void pop_front() {
        if (empty()) {
            throw std::logic_error("Nothing in the front to pop\n");
        }
        Node* node {head};
        head = node->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete node;
        size_--;
    }

    void pop_back() {
        if (empty()) {
            throw std::logic_error("Nothing in the back to pop \n");
        }
        Node* node {tail};
        tail = node->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete node;
        size_--;
    }
};

#endif // LEARN_CPP_DOUBLYLINKEDLIST_H
