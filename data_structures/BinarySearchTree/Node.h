//
// Created by Mosa Yaqoobi on 2026-04-04.
//

#ifndef LEARN_CPP_NODE_H
#define LEARN_CPP_NODE_H

struct Node {
    int key {};
    Node* left {nullptr};
    Node* right {nullptr};
    Node(int key) : key(key) {}
    Node(int key, Node* left, Node* right) :
    key(key), left(left), right(right) {}
};

#endif //LEARN_CPP_NODE_H
