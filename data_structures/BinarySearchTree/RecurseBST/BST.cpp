//
// Created by Mosa Yaqoobi on 2026-04-05.
//

#include "BST.h"

#include <iostream>
#include <optional>
#include <queue>

void levelOrder_(const Node* node) noexcept {
    if (!node) {
        return;
    }
    std::queue<const Node*> q;
    q.push(node);
    while (!q.empty()) {
        std::cout << q.front()->key << " ";
        auto temp = q.front();
        q.pop();
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
}

std::optional<int> BST::findMinFromSubtree(const Node* node) noexcept {
    if (!node) { // if no root, just return a null pointer
        return std::nullopt;
    }
    while (node->left) { // recurse to the far left leaf, which is where the min is
        node = node->left;
    }
    return node->key;
}

std::optional<int> BST::findMaxFromSubtree(const Node* node) noexcept {
    if (!node) {
        return std::nullopt;
    }
    while (node->right) {
        node = node->right;
    }
    return node->key;
}

Node* BST::remove_(Node* node, int key) noexcept {
    if (!node) {
        return nullptr;
    }
    if (node->key > key) {
        node->left = remove_(node->left, key);
    } else if (node->key < key) {
        node->right = remove_(node->right, key);
    }
    if (node->key == key) {
        Node* temp {};
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        } else if (node->left && !node->right) {
            temp = node->left;
            delete node;
            return temp;
        } else if (!node->left && node->right) {
            temp = node->right;
            delete node;
            return temp;
        } else if (node->left && node->right) {
            // find the smallest node within the right subtree
            // assign that to current, then remove it from the tree
            auto val {findMinFromSubtree(node->right)};
            node->key = val.value();
            node->right = remove_(node->right, val.value());
            return node;
        }
    }
    return node;
}

Node* BST::insert_(Node* node, int key) {
    if (!node) { // base case (if no node, then make a new node, and return that)
        Node* newNode = new Node(key);
        return newNode;
    }
    if (node->key > key) { // node exists, just recurse down the correct path
        node->left = insert_(node->left, key);
    } else if (node->key < key) {
        node->right = insert_(node->right, key);
    }
    return node; // return the node if it gets placed
}

Node* BST::search_(Node* node, int key) noexcept {
    if (!node) {
        return nullptr;
    }
    if (node->key == key) {
        return node;
    } else if (node->key > key) {
        return search_(node->left, key);
    } else if (node->key < key) {
        return search_(node->right, key);
    }
    return node;
}

int BST::height_(const Node* node) noexcept {
    if (!node) {
        return 0;
    }
    return std::max(height_(node->left), height_(node->right)) + 1;
}

void BST::preOrder_(const Node* node) noexcept {
    if (!node) {
        return;
    }
    std::cout << node->key << " ";
    preOrder_(node->left);
    preOrder_(node->right);
}

void BST::inOrder_(const Node* node) noexcept {
    if (!node) {
        return;
    }
    inOrder_(node->left);
    std::cout << node->key << " ";
    inOrder_(node->right);
}

void BST::postOrder_(const Node* node) noexcept {
    if (!node) {
        return;
    }
    postOrder_(node->left);
    postOrder_(node->right);
    std::cout << node->key << " ";
}

Node* BST::getRoot() const noexcept {
    return root;
}

bool BST::isEmpty() const noexcept {
    if (getRoot()) {
        return false;
    }
    return true;
}

bool BST::search(int val) const noexcept {
    return (search_(getRoot(), val) != nullptr);
}

void BST::insert(int val) {
    root = insert_(root, val);
}

void BST::remove(int key) const {
    remove_(getRoot(), key);
}

std::optional<int> BST::findMin() const noexcept {
    return findMinFromSubtree(getRoot());
}

std::optional<int> BST::findMax() const noexcept {
    return findMaxFromSubtree(getRoot());
}

void BST::preOrder() const noexcept {
    preOrder_(getRoot());
}

void BST::inOrder() const noexcept {
    inOrder_(getRoot());
}

void BST::postOrder() const noexcept {
    postOrder_(getRoot());
}

int BST::height() const noexcept {
    return height_(getRoot());
}
