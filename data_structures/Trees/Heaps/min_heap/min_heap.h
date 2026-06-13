//
// Created by Mosa Yaqoobi on 2026-06-04.
//

#ifndef LEARN_CPP_MIN_HEAP_H
#define LEARN_CPP_MIN_HEAP_H
#include <vector>
// Parent: (i - 1) / 2
// left child: 2 * i + 1
// right child: 2 * i + 2
template <typename T>
class MinHeap {
    std::vector<T> heap{};
    void siftUp(T i) {}
    void siftDown(T i) {}
    void siftDown(int i) {

        while (i < heap.size()) {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
            int smallest = i;

            if (leftChild < heap.size() && heap[smallest] > heap[leftChild]) {
                smallest = leftChild;

            } if (rightChild < heap.size() && heap[smallest] > heap[rightChild]) {
                smallest = rightChild;

            } if (smallest == i) {
                break;
            }
            std::swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }
public:
    [[nodiscard]] std::size_t size() const { return heap.size(); }
    [[nodiscard]] bool empty() const {return heap.size() == 0; }
    [[nodiscard]] T getMin() const {return heap[0]; }
    void push(const T value) {}
    T pop() {}




};

#endif //LEARN_CPP_MIN_HEAP_H
