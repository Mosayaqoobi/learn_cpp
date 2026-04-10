//
// Created by Mosa Yaqoobi on 2026-04-05.
//
#include "BST.h"

Node* BST::getRoot() const noexcept {
    return root;
}

bool BST::search(int val) const noexcept {
    Node* node = root;
    while (node != nullptr && val != node->key) {
        if (val < node->key) {
            node = node->left;
        } else if (val > node->key) {
            node = node->right;
        }
    }
    return node != nullptr;
}

void BST::insert(int val) {
    if (root == nullptr) {
        Node* newNode = new Node(val);
        root = newNode;
        return;
    }
    Node* parent = nullptr;
    Node* current {getRoot()};
    while (current != nullptr) {
        if (current->key < val) {
            parent = current;
            current = current->right;
        } else if (current->key > val) {
            parent = current;
            current = current->left;
        } else if (current->key == val) {
            return;
        }
    }
    Node* newNode = new Node(val);
    if (parent->key > val) {
        parent->left = newNode;
    } else if (parent->key < val) {
        parent->right = newNode;
    }
}

std::optional<int> BST::findMinFromSubtree(const Node* node) noexcept {
    if (!node) {
        return std::nullopt;
    }
    while (node->left != nullptr) {
        node = node->left;
    }
    return node->key;
}
std::optional<int> BST::findMaxFromSubtree(const Node* node) noexcept {
    if (!node) {
        return std::nullopt;
    }
    while (node->right != nullptr) {
        node = node->right;
    }
    return node->key;
}
std::optional<int> BST::findMax() const noexcept {
    return findMaxFromSubtree(root);
}
std::optional<int> BST::findMin() const noexcept {
    return findMinFromSubtree(root);
}

