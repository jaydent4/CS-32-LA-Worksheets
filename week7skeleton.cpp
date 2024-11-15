// BINARY TREE NODE IMPLEMENTATION
template <typename Type>
class BinaryTreeNode {
    public:
        BinaryTreeNode( const Type & theElement,
                        BinaryTreeNode * theLeftSide = nullptr,
                        BinaryTreeNode * theRightSide = nullptr );
        const Type& getElement() const;
        BinaryTreeNode* getLeftSide() const;
        BinaryTreeNode* getRightSide() const;
        void setLeftSide( BinaryTreeNode* node );
        void setRightSide( BinaryTreeNode* node );
    private:
        Type element;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
};

template <typename Type>
BinaryTreeNode<Type>::BinaryTreeNode(const Type & theElement, BinaryTreeNode* theLeftSide = nullptr, BinaryTreeNode* theRightSide = nullptr ) : element(theElement), left(theLeftSide), right(theRightSide) {}

template <typename Type>
const Type& BinaryTreeNode<Type>::getElement() const { return element; }

template <typename Type>
BinaryTreeNode<Type>* BinaryTreeNode<Type>::getLeftSide() const { return left; }

template <typename Type>
BinaryTreeNode<Type>* BinaryTreeNode<Type>::getRightSide() const { return right; }

template <typename Type>
void BinaryTreeNode<Type>::setLeftSide(BinaryTreeNode* node) { left = node; }

template <typename Type>
void BinaryTreeNode<Type>::setRightSide(BinaryTreeNode* node) { right = node; }

// N-ARY TREE NODE IMPLEMENTATION
#include <vector>
using namespace std;

template <typename Type>
class TreeNode {
    public:
        TreeNode( const Type & theElement );
        const Type& getElement() const;
        vector<TreeNode*> getChildren();
    private:
        Type element;
        vector<TreeNode*> children;
};

template <typename Type>
TreeNode<Type>::TreeNode(const Type& theElement) : element(theElement) {}

template <typename Type>
const Type& TreeNode<Type>::getElement() const { return element; }

template <typename Type>
vector<TreeNode<Type>*> TreeNode<Type>::getChildren() { return children; }


// QUESTION 1
template <typename Type>
bool treeContains(BinaryTreeNode<Type>* head, Type n) {
    return false;
}


// QUESTION 2
template <typename Type>
int countLeaves(TreeNode<Type>* root) {
    return -1;
}

// QUESTION 3
template <typename Type>
vector<Type> inorderTraversal(BinaryTreeNode<Type>* root) {
    vector<Type> nodes;
    return nodes;
}

template <typename Type>
vector<Type> preorderTraversal(BinaryTreeNode<Type>* root) {
    vector<Type> nodes;
    return nodes;
}

template <typename Type>
vector<Type> postorderTraversal(BinaryTreeNode<Type>* root) {
    vector<Type> nodes;
    return nodes;
}

// QUESTION 4
template <typename Type>
bool isSubtree(BinaryTreeNode<Type>* main, BinaryTreeNode<Type>* potential) {
    return false;
}

// QUESTION 5

template <typename Type>
void reverse(BinaryTreeNode<Type>* root) {
    return;
}

// QUESTION 6

int getGreatestPath(BinaryTreeNode<int>* root) {
    return -1;
}

// QUESTION 7

/*
in-order: 4 2 5 1 6 7 3 8
post-order: 4 5 2 6 7 8 3 1
*/