//
// Created by Mosa Yaqoobi on 2026-04-09.
//

#ifndef LEARN_CPP_AVL_TREE_H
#define LEARN_CPP_AVL_TREE_H

#include "Node.h"

class AVLTree {
    Node* root {};
    static int getHeight(const Node* node) noexcept;
    static int getBalanceFactor(Node* node) noexcept;
    static Node* findMinNode(Node* node) noexcept;
    static void updateHeight(Node* node) noexcept;
    static Node* rightRotate(Node* node) noexcept;
    static Node* leftRotate(Node* node) noexcept;
    static Node* balance(Node* node) noexcept;
    static Node* insert_(Node* node, int val) noexcept;
    static Node* remove_(Node* node, int val) noexcept;
    static Node *search_(Node *node, int val) noexcept;

public:
    void insert(int val) noexcept;
    void remove(int val);
    [[nodiscard]] bool search(int val) const noexcept;
    [[nodiscard]] int findMin() const noexcept;
    [[nodiscard]] int findMax() const noexcept;
    [[nodiscard]] int height() const noexcept;
    [[nodiscard]] bool isEmpty() const noexcept;
    [[nodiscard]] Node* getRoot() const noexcept;
};

#endif //LEARN_CPP_AVL_TREE_H
