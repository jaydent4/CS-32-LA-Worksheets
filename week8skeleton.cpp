// CODING QUESTIONS

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>
#include <cassert>

int firstUniqueChar(std::string s) {

}

// Pulled from Leetcode (slight modification): https://leetcode.com/problems/two-sum/description/
int twoSum(int arr[], int n, int target) {

}


bool isMaxHeapOrdered(const int arr[], int len) {

}


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

}



template <typename T>
BinaryTreeNode<T>* makeMaxHeap(const T a[], int n) {
    
}


// MORE CODING QUESTIONS
void inRange(int arr[], int n, int low, int high) {

}

// Pulled from Leetcode and simplified (https://leetcode.com/problems/3sum/description/)
bool sum3(const int arr[], int n) {

}


int main() {
    
}