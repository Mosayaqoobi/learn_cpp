//
// Created by Mosa Yaqoobi on 2026-04-04.
//

#ifndef LEARN_CPP_BINARYSEARCHTREE_H
#define LEARN_CPP_BINARYSEARCHTREE_H

#include "Node.h"
#include <optional>

class BST {
    Node* root {nullptr};
    Node* insert_(Node* node, const int key);
    Node* search_(Node* node, const int key) const noexcept;
    Node* remove_(Node* node, const int key) noexcept;

    void preOrder_(const Node* node) const noexcept;
    void inOrder_(const Node* node) const noexcept;
    void postOrder_(const Node* node) const noexcept;
    int height_(const Node* node) const noexcept;
    std::optional<int> findMinFromSubtree(const Node* node) const noexcept;
    std::optional<int> findMaxFromSubtree(const Node* node) const noexcept;

public:
    BST() = default;
    BST(Node* root_node) : root(root_node) {}
    void insert(const int val);
    std::optional<int> search(const int val) const noexcept;
    void remove(const int key);
    void inOrder() const noexcept;
    void preOrder() const noexcept;
    void postOrder() const noexcept;
    std::optional<int> findMin() const noexcept;
    std::optional<int> findMax() const noexcept;
    int height() const noexcept;
    bool isEmpty() const noexcept;
    Node* getRoot() const noexcept;


};

#endif //LEARN_CPP_BINARYSEARCHTREE_H
