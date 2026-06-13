//
// Created by Mosa Yaqoobi on 2026-06-04.
//
#include <ostream>
#include <print>
#include <stdexcept>
#include <vector>

template <typename T>
class MinHeap {
    std::vector<T> heap {};

    void siftUp(int i) {

        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] < heap[parent]) {
                std::swap(heap[i], heap[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void siftDown(int i) {

        while (i < heap.size()) {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
            int smallest = i;

            if (leftChild < heap.size() && heap[smallest] > heap[leftChild]) {
                smallest = leftChild;
            }
            if (rightChild < heap.size() && heap[smallest] > heap[rightChild]) {
                smallest = rightChild;
            }
            if (smallest == i) {
                break;
            }
            std::swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

  public:
    [[nodiscard]] std::size_t size() const {
        return heap.size();
    }

    [[nodiscard]] bool empty() const {
        return heap.empty();
    }

    [[nodiscard]] T getMin() const {
        if (!empty()) {
            return heap[0];
        }
        throw std::out_of_range("heap is empty");
    }

    void push(const T& value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    void pop() {
        if (empty()) {
            std::println("heap empty");
            return;
        }
        std::swap(heap[0], heap.back());
        heap.pop_back();
        siftDown(0);
    }
};
