//
// Created by Mosa Yaqoobi on 2026-04-05.
//

#ifndef LEARN_CPP_BST_H
#define LEARN_CPP_BST_H

#include "../Node.h"
#include <optional>

class BST {
    Node* root {nullptr};
    static std::optional<int> findMinFromSubtree(const Node* node) noexcept;
    static std::optional<int> findMaxFromSubtree(const Node* node) noexcept;

public:
    BST() = default;

    explicit BST(Node* root_node) : root(root_node) {}

    void insert(int val);

    [[nodiscard]] bool search(int val) const noexcept;
    void remove(int key) const;
    void inOrder() const noexcept;
    void preOrder() const noexcept;
    void postOrder() const noexcept;
    void levelOrder() const noexcept;
    [[nodiscard]] std::optional<int> findMin() const noexcept;
    [[nodiscard]] std::optional<int> findMax() const noexcept;
    [[nodiscard]] int height() const noexcept;
    [[nodiscard]] bool isEmpty() const noexcept;
    [[nodiscard]] Node* getRoot() const noexcept;
};

#endif //LEARN_CPP_BST_H
