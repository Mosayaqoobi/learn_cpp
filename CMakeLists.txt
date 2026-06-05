cmake_minimum_required(VERSION 3.30)

# 2. Set the standard BEFORE the project call so the compiler is probed correctly
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

# 3. Now initialize the project
project(learn_cpp LANGUAGES CXX)


add_executable(
        learn_cpp
        data_structures/ByteRing/ByteRing.h
        main.cpp
        data_structures/LinkedList/linkedlist.h
        data_structures/LinkedList/doublylinkedlist.h
        OOP/BankAccount/Money.h
        OOP/BankAccount/Account.h
        OOP/BankAccount/Ledger.h
        OOP/BankAccount/Transaction.h
        data_structures/Stack/FixedStack.h
        data_structures/Queue/Queue.h
        "leetcode solutions/easy/isMonotonic.cpp"
        "leetcode solutions/medium/addTwoNumbers.cpp"
        "leetcode solutions/easy/addBinary.cpp"
        data_structures/Trees/BinarySearchTree/RecurseBST/BST.h
        data_structures/Trees/BinarySearchTree/Node.h
        data_structures/Trees/BinarySearchTree/RecurseBST/BST.cpp
        data_structures/Trees/BinarySearchTree/iterativeBST/BST.h
        data_structures/Trees/BinarySearchTree/iterativeBST/BST.cpp
        data_structures/Trees/AVL_Tree/Node.h
        data_structures/Trees/AVL_Tree/AVL_Tree.h
        data_structures/Trees/AVL_Tree/AVL_Tree.cpp
        data_structures/Graph/Graph.h
        data_structures/Graph/Graph.cpp
        "leetcode solutions/easy/mergeAlternately.cpp"
        "leetcode solutions/easy/kidsWithCandies.cpp"
        "leetcode solutions/easy/gcdOfStrings.cpp"
        "leetcode solutions/easy/canPlaceFlowers.cpp"
        "leetcode solutions/easy/reverseVowels.cpp"
        "leetcode solutions/medium/reverseWords.cpp"
        "leetcode solutions/medium/productExceptSelf.cpp"
        "leetcode solutions/medium/increasingTriplet.cpp"
        "leetcode solutions/easy/moveZeroes.cpp"
        "leetcode solutions/medium/compress.cpp"
        "leetcode solutions/easy/guessNumber.cpp"
        "leetcode solutions/easy/findMaxAverage.cpp"
)