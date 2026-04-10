cmake_minimum_required(VERSION 3.16)

project(learn_cpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        learn_cpp
        data_structures/ByteRing/ByteRing.h
        main.cpp
        data_structures/LinkedList/linkedlist.h
        data_structures/LinkedList/main.cpp
        data_structures/LinkedList/doublylinkedlist.h
        OOP/BankAccount/Money.h
        OOP/BankAccount/Account.h
        OOP/BankAccount/Ledger.h
        OOP/BankAccount/Transaction.h
        Random/test.cpp
        data_structures/Stack/FixedStack.h
        data_structures/Queue/Queue.h
        temp.cpp
        "leetcode solutions/easy/isMonotonic.cpp"
        "leetcode solutions/medium/addTwoNumbers.cpp"
        "leetcode solutions/easy/addBinary.cpp"
        data_structures/BinarySearchTree/RecurseBST/BST.h
        data_structures/BinarySearchTree/Node.h
        data_structures/BinarySearchTree/RecurseBST/BST.cpp
        data_structures/BinarySearchTree/iterativeBST/BST.h
        data_structures/BinarySearchTree/iterativeBST/BST.cpp
        data_structures/AVL_Tree/Node.h
)