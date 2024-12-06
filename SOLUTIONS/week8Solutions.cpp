// CODING QUESTIONS

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>
#include <cassert>

int firstUniqueChar(std::string s) {
    std::unordered_map<char, int> frequency;
    for (int i = 0; i < s.size(); i++) {
        if (frequency.find(s[i]) != frequency.end()) {
            frequency[s[i]]++;
        }
        else {
            frequency[s[i]] = 1;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (frequency[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}
/*
INTUITION:
We will do a two pass solution for this question. In each pass:

    Pass 1: obtain the frequency of each character
    Pass 2: check whether the frequency of a given character is 1

Once we find the first character that is unique (frequency of 1) return that index
*/

// Pulled from Leetcode (slight modification): https://leetcode.com/problems/two-sum/description/
int twoSum(int arr[], int n, int target) {
    std::unordered_set<int> needed;
    for (int i = 0; i < n; i++) {
        if (needed.find(arr[i]) != needed.end()) {
            return true;
        }
        else {
            needed.insert(n - arr[i]);
        }
    }
    return false;
}
/*
INTUITION: 
For every given number, we know that the other number must be the difference of the current number from the target:
a + b = target => b = target - a
We use a set to determine which numbers we need to complete a pair of an already visited number
NOTE: The leetcode version (more common) asks you to return a vector of the two indices, how can we adjust our algorithm to do this?
        We want to use a hashmap to hold the index of the first element of the complement.
        We would use a hashmap in the following way:

            hashmap[target - a] = index of a

        This allows us to "remember" what the index of the a is so that when we find b, we can access the index of a
*/

bool isMaxHeapOrdered(const int arr[], int len) {
    for (int i = 0; i < len; i++) {
        if ((2*i + 1 < len && arr[i] < arr[2*i + 1]) || (2*i + 2 < len && arr[i] < arr[2*i + 2])) {
            return false;
        }
    }
    return true;
}
/*
INTUITION:
To represent a binary tree in an array, we need to have a deterministic way to find the children of a given element.
We use the following convention:

    For a given parent at index i,
        left child = 2 * i + 1
        right child = 2 * i + 2
    
    If a left child or right child does not exist and it is not the end of the array, we substitute the value for some null value
    A nonexistent parent cannot have children (naturally)

In this question, we assume that our array is valid
A max heap guarantees that the parent value is always greater than the children values
For each iteration, we check if the children exists and if the children value is greater than the parent value (not max heap) and return false if condition ever holds.
*/

template <typename T>
class BinaryTreeNode {
    public:
        BinaryTreeNode(const T & theElement, BinaryTreeNode* theLeftSide = nullptr, BinaryTreeNode* theRightSide = nullptr );
        const T& getElement() const;
        BinaryTreeNode<T>* getLeftSide() const;
        BinaryTreeNode<T>* getRightSide() const;
        void setLeftSide( BinaryTreeNode* node );
        void setRightSide( BinaryTreeNode* node );
    private:
        T mElement;
        BinaryTreeNode<T>* mLeftSide;
        BinaryTreeNode<T>* mRightSide;
};

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T & theElement, BinaryTreeNode* theLeftSide = nullptr, BinaryTreeNode* theRightSide = nullptr ) : mElement(theElement), mLeftSide(theLeftSide), mRightSide(theRightSide) {}

template <typename T>
const T& BinaryTreeNode<T>::getElement() const { return mElement; }

template <typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftSide() const { return mLeftSide; }

template <typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRightSide() const { return mRightSide; }

template <typename T>
void BinaryTreeNode<T>::setLeftSide(BinaryTreeNode* node) { mLeftSide = node; }

template <typename T>
void BinaryTreeNode<T>::setRightSide(BinaryTreeNode* node) { mRightSide = node; }

template <typename T>
bool isMinHeapOrdered(const BinaryTreeNode<T>* root) {
    if (root == nullptr) { return true; }
    if ((root->getLeftSide() != nullptr && root->getElement() > root->getLeftSide()->getElement()) || (root->getRightSide() != nullptr && root->getElement() > root->getRightSide()->getElement())) { return false; }
    return isMinHeapOrder(root->getLeftSide()) && isMinHeapOrder(root->getRightSide());
}
/*
INTUITION:
A min heap guarantees that the parent value is less than or equal to the children values.
We will do this recursively:
    
    Base Case(s): 
        if the tree is empty, the tree is a min heap
        if we have a left child and our left child's value is strictly less than our parent value, then return false
        if we have a right child and our right child's value is strictly less than our parent value, then return true
    Inductive Step:
        Recursively call 
        
*/

// Define a helper function

template <typename T>
BinaryTreeNode<T>* helper(const T a[], int i, int n) {
    if (i >= n) { return nullptr; }
    BinaryTreeNode<T>* root = new BinaryTreeNode<T>(a[i]);
    root->setLeftSide(helper(a, 2 * i + 1, n));
    root->setRightSide(helper(a, 2 * i + 2, n));
    return root;
}

template <typename T>
BinaryTreeNode<T>* makeMaxHeap(const T a[], int n) {
    return helper(a, 0, n);
}
/*
INTUITION:
Given the structure of the original function where we cannot keep track of the current index we are on, we will use a helper function that keeps track of our current index (i).

Base Case: if i >= n, we are out of range of the array (node does not exist), so we return nullptr

We create a node for our current value.

Inductive Step: We call the function on the left child (2 * i + 1) and the right child (2 * i + 2) (call should return the root of the subtrees), which we assign to the left and right side of our starting node, respectively.
*/


// HASH TABLE QUESTIONS
/*

Insert { 1, 11, 21, 33, 14, 24, 34 }

6. The linear probing collision resolution scheme places a value in their calculated hash bucket unless it the bucket is full, in which it will search for the next available bucket

    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    | index |   0   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |
    |       |       |       |       |       |       |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    | value |       |   1   |  11   |  21   |  33   |  14   |  24   |  34   |       |       |
    |       |       |       |       |       |       |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+

    STEPS
    1. H(1) = 1, place in index 1
    2. H(11) = 1, index 1 is taken, so 11 will to into the next index (index 2)
    3. H(21) = 1, index 1 is taken, index 2 is taken, place in index 3
    4. H(33) = 3, index 3 is taken, place in index 4
    5. H(14) = 4, index 4 is taken, place in index 5
    6. H(24) = 4, index 4 is taken, index 5 is taken, place in index 6
    7. H(34) = 4, index 4 is taken, index 5 is taken, index 6 is taken, place in index 7

    This method is good when the load factor is low and values are not consecutive or equal

7. The quadratic probing collision resolution scheme places a value in their calculated hash bucket unless it is filled.
   It will find the next unfilled bucket using the following formula:
    
    i = (i_prev + (n^2)) % S for some n (n starts from 1 and continues to increment)

    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    | index |   0   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |
    |       |       |       |       |       |       |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    | value |       |   1   |  11   |  33   |  14   |  24   |  21   |       |       |  34   |
    |       |       |       |       |       |       |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+

    STEPS
    1. H(1) = 1, place in index 1
    2. H(11) = 1, index 1 is taken, (1 + (1)^2) = 2, place in index 3
    3. H(21) = 1, index 1 is taken, (1 + (1)^2) = 2, index 2 is taken, (2 + (2)^2) = 6, place in index 6.
    4. H(33) = 3, place in index 3
    5. H(14) = 4, place in index 4
    6. H(24) = 4, index 4 is taken, (4 + (1)^2) = 5, place in index 5
    7. H(34) = 4, index 4 is taken, (4 + (1)^2) = 5, index 5 is taken, (5 + (2)^2) = 9, place in index 9

    This solves the issue with consecutive buckets being taken up, but can still lead to the same issue in secondary iterations of the collsion

8. 

    +-------+-------+-------+-------+-------+--------+-------+-------+-------+-------+-------+
    | index |   0   |   1   |   2   |   3   |   4    |   5   |   6   |   7   |   8   |   9   |
    |       |       |       |       |       |        |       |       |       |       |       |
    +-------+-------+-------+-------+-------+--------+-------+-------+-------+-------+-------+
    | value |       |1,11,21|       |  33   |14,24,34|       |       |       |       |       |
    |       |       |       |       |       |        |       |       |       |       |       |
    +-------+-------+-------+-------+-------+--------+-------+-------+-------+-------+-------+

    STEPS
    We place each number in the index that the hash function outputs. We represent this type of hashmap as an array of linked lists.
*/

// MORE CODING QUESTIONS
void inRange(int arr[], int n, int low, int high) {
    std::unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        seen.insert(arr[i]);
    }

    for (int x = low; x <= high; x++) {
        if (seen.find(x) == seen.end()) {
            std::cout << x << " ";
        }
    }
}
/*
INTUITION:
We use a set to easily determine what numbers are actually in arr.
We iterate through each number in range [low, high] to find which numbers are not included in the set.
*/

// Pulled from Leetcode and simplified (https://leetcode.com/problems/3sum/description/)
bool sum3(const int arr[], int n) {
    std::unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        seen.insert(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int remaining = (arr[i] + arr[j]) * -1;
            if (remaining != arr[i] && remaining != arr[j] && seen.find(remaining) != seen.end()) {
                return true;
            }
        }
    }
    return false;
}
/*
INTUITION:
Like previous questions, we need to be able to find what numbers exist in our array. We use a set to do this.
We use a similar idea to TwoSum, where we keep track of what number we "need" to determine if such triplet exists.

To determine the third number, we use the following formula. Let a, b, c be the three numbers:

    a + b + c = 0
    c = - a - b
    c = -(a + b)

We define c to be "remaining" in our algorithm.

To check for no duplicate numbers, we check whether our remaining is equal to any of our other two numbers.
*/


int main() {
    
}