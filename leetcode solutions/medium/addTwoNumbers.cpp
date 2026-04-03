#include <iostream>
#include <ostream>
//
// Created by Mosa Yaqoobi on 2026-04-01.
//
using namespace std;
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void addTwoNumbers(ListNode* l1, ListNode* l2) {
    vector<int> num1 {};
    vector<int> num2 {};
    ListNode* temp1 = {l1};
    ListNode* temp2 = {l2};

    while (temp1) {
        num1.push_back(temp1->val);
        temp1 = temp1->next;
    }
    while (temp2) {
        num2.push_back(temp2->val);
        temp2 = temp2->next;
    }
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());



}

int main() {
    ListNode a (5);
    ListNode b (0);
    ListNode c (8 );

    ListNode d (4);
    ListNode e (0);
    ListNode f (2);
    a.next = &b;
    b.next = &c;
    d.next = &e;
    e.next = &f;

    addTwoNumbers(&a, &d);


}

