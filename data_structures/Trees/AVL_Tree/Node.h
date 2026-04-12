//
// Created by Mosa Yaqoobi on 2026-04-09.
//

#ifndef LEARN_CPP_NODE_H
#define LEARN_CPP_NODE_H

struct Node {
    int key {};
    Node* left {nullptr};
    Node* right {nullptr};
    int height {};
    Node(int key) : key{key}, height{1} {};
};

#endif //LEARN_CPP_NODE_H
