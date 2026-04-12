//
// Created by Mosa Yaqoobi on 2026-04-09.
//

#include "AVL_Tree.h"

#include <algorithm>
#include <ios>

int AVLTree::getHeight(const Node *node) noexcept {
    return node ? node->height : 0;
}

int AVLTree::getBalanceFactor(Node *node) noexcept {
    if (!node) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}
Node *AVLTree::findMinNode(Node *node) noexcept {
    if (!node) {
        return nullptr;
    }
    while (node->left) {
        node = node->left;
    }
    return node;
}

void AVLTree::updateHeight(Node *node) noexcept {
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

Node *AVLTree::rightRotate(Node *node) noexcept {
    Node* x = node->left;
    node->left = x->right;
    x->right = node;
    updateHeight(node);
    updateHeight(x);
    return x;
}

Node *AVLTree::leftRotate(Node *node) noexcept {
    Node* x = node->right;
    node->right = x->left;
    x->left = node;
    updateHeight(node);
    updateHeight(x);
    return x;
}

Node *AVLTree::balance(Node *node) noexcept {
    if (getBalanceFactor(node) > 1) {
        if (getBalanceFactor(node->left) >= 0) {
            return rightRotate(node);
        } else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    } else if (getBalanceFactor(node) < -1) {
        if (getBalanceFactor(node->right) <= 0) {
            return leftRotate(node);
        } else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    } else {
        return node;
    }
}

Node *AVLTree::insert_(Node *node, int val) noexcept {
    if (!node) {
        Node* newNode = new Node(val);
        return newNode;
    }
    if (node->key > val) {
        node->left = insert_(node->left, val);
    } else if (node->key < val) {
        node->right = insert_(node->right, val);
    }
    updateHeight(node);
    return balance(node);
}

Node* AVLTree::remove_(Node* node, const int val) noexcept {
    if (!node) {
        return nullptr;
    }
    if (node->key > val) {
        node->left = remove_(node->left, val);
    } else if (node->key < val) {
        node->right = remove_(node->right, val);
    }
    else if (node->key == val) {
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
            auto node1 {findMinNode(node->right)};
            node->key = node1->key;
            node->right = remove_(node->right, node1->key);
        }
    }
    updateHeight(node);
    return balance(node);
}

Node *AVLTree::search_(Node *node, int val) noexcept {
    if (!node) {
        return nullptr;
    }
    if (node->key == val) {
        return node;
    } else if (node->key > val) {
        return search_(node->left, val);
    } else if (node->key < val) {
        return search_(node->right, val);
    }
    return node;
}

void AVLTree::insert(int val) noexcept {
    root = insert_(root, val);
}

void AVLTree::remove(int val) {
    root = remove_(root, val);
}

bool AVLTree::search(int val) const noexcept {
    return (search_(getRoot(), val) != nullptr);
}

int AVLTree::findMin() const noexcept {
    if (!getRoot()) {
        return -1;
    }
    const Node* node {getRoot()};
    while (node->left) {
        node = node->left;
    }
    return node->key;
}

int AVLTree::findMax() const noexcept {
    if (!getRoot()) {
        return -1;
    }
    const Node* node {getRoot()};
    while (node->right) {
        node = node->right;
    }
    return node->key;

}

int AVLTree::height() const noexcept {
    return getHeight(getRoot());
}

bool AVLTree::isEmpty() const noexcept {
    return getRoot() == nullptr;
}

Node *AVLTree::getRoot() const noexcept {
    return root;
}

