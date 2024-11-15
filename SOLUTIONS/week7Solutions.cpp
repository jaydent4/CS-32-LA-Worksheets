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
    if (head == nullptr) { return false; } // an empty tree cannot contain n
    if (head->getElement() == n) { return true; } // we found our element
    return treeContains(head->getLeftSide(), n) || treeContains(head->getRightSide(), n); // explore each side of the tree
}
// NOTE: we can also do this iteratively using a data structure (one covered in this class already)


// QUESTION 2
template <typename Type>
int countLeaves(TreeNode<Type>* root) {
    if (root == nullptr) { return 0; }
    if (root->getChildren().size() == 0) { return 1; }
    int leaves = 0;
    for (int i = 0; i < root->getChildren().size(); i++) {
        leaves += countLeaves(root->getChildren()[i]);
    }
    return leaves;
}

// QUESTION 3

// Define a helper function (function structure is not conducive to doing this recursively)

// Recursive Solution
template <typename Type>
void inorder(BinaryTreeNode<Type>* root, vector<Type>& nodes) {
    if (root == nullptr) { return; }
    inorder(root->getLeftSide(), nodes);
    nodes.push_back(root->getElement());
    inorder(root->getRightSide(), nodes);
}

template <typename Type>
vector<Type> inorderTraversal(BinaryTreeNode<Type>* root) {
    vector<Type> nodes;
    inorder(root, nodes);
    return nodes;
}

// Iterative Solution
#include <stack>

template <typename Type>
vector<Type> inorderTraversalIterative(BinaryTreeNode<Type>* root) {
    vector<Type> nodes;
    stack<TreeNode*> s;
    BinaryTreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        while (curr != nullptr) { // Iterate all the way to the left
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        nodes.push_back(current->getElement());
        current = current->right;
    }
    return nodes;
}

// Recursive Solution
template <typename Type>
void preorder(BinaryTreeNode<Type>* root, vector<Type>& nodes) {
    if (root == nullptr) { return; }
    nodes.push_back(root->getElement());
    preorder(root->getLeftSide(), nodes);
    preorder(root->getRightSide(), nodes);
}

template <typename Type>
vector<Type> preorderTraversal(BinaryTreeNode<Type>* root) {
    vector<Type> nodes;
    preorder(root, nodes);
    return nodes;
}

// Iterative Solution
template <typename Type>
vector<Type> preorderTraversalIterative(BinaryTreeNode<Type>* root) {
    if (root == nullptr) { return; }
    vector<Type> nodes;
    stack<TreeNode*> s;
    s.push(root);
    BinaryTreeNode* current;
    while (!s.empty()) {
        current = s.top();
        nodes.push_back(current);
        if (current->getRight()) { s.push(current->getRight()); }
        if (current->getLeft()) { s.push(current->getLeft()); }
    }
    return nodes;
}

// Recursive Solution
template <typename Type>
void postorder(BinaryTreeNode<Type>* root, vector<Type>& nodes) {
    if (root == nullptr) { return; }
    preorder(root->getLeftSide(), nodes);
    preorder(root->getRightSide(), nodes);
    nodes.push_back(root->getElement());
}

template <typename Type>
vector<Type> postorderTraversal(BinaryTreeNode<Type>* root) {
    vector<Type> nodes;
    preorder(root, nodes);
    return nodes;
}

// Iterative Solution
template <typename Type>
vector<Type> preorderTraversalIterative(BinaryTreeNode<Type>* root) {
    if (root == nullptr) { return; }
    vector<Type> nodes;
    stack<TreeNode*> s1, s2;
    s1.push(root);
    TreeNode* current;
    while (!s1.empty()) {
        current = s1.top();
        s1.pop();
        s2.push(current);
        if (current->getRight()) { s1.push(current->getRight()); }
        if (current->getLeft()) { s1.push(current->getLeft()); }
    }
    while (!s2.empty()) {
        current = s2.top();
        s2.pop();
        nodes.push_back(current->getElement());
    }
    return nodes;
}

// QUESTION 4

// Helper Function
template <typename Type>
bool identical(BinaryTreeNode<Type>* r1, BinaryTreeNode<Type>* r2) {
    if (r1 == nullptr && r2 == nullptr) { return true; }
    if (r1 == nullptr || r2 == nullptr) { return false; }
    return (r1->getElement() == r2->getElement() && identical(r1->getLeftSide(), r2->getLeftSide()) && identical(r1->getRightSide(), r2->getRightSide()));
}

template <typename Type>
bool isSubtree(BinaryTreeNode<Type>* main, BinaryTreeNode<Type>* potential) {
    if (potential == nullptr) { return true; }
    if (main == nullptr) { return false; }
    if (identical(main, potential)) { return true; }
    return isSubtree(main->getLeftSide(), potential) || isSubtree(main->getRightSide(), potential);
}

// QUESTION 5

template <typename Type>
void reverse(BinaryTreeNode<Type>* root) {
    if (root == nullptr) { return; }
    BinaryTreeNode* temp = root->getLeftSide();
    root->setLeftSide(root->getRightSide());
    root->setRightSide(temp);
    reverse(root->getleftSide());
    reverse(root->getRightSide());
}

// QUESTION 6

int getGreatestPath(BinaryTreeNode<int>* root) {
    if (root == nullptr) { return 0; }
    int leftMax = getGreatestPath(root->getLeftSide());
    int rightMax = getGreatestPath(root->getRightSide());

    return (leftMax > rightMax) ? root->getElement() + leftMax : root->getElement() + rightMax;
}

// QUESTION 7

/*
in-order: 4 2 5 1 6 7 3 8
post-order: 4 5 2 6 7 8 3 1

We can find the root easily because it must be the last item in the post-order list

Tree:               1

Now we know what must be in the left and right subtree from the in-order list
in-order: 4 2 5 left <- (1) -> right 6 7 3 8

With this information, we can find the roots of the left and right subtree. They must be the last item of their "side"
post-order: (4 5 2)->left (6 7 8 3)->right (1)->root

Tree:               1
                  /   \
                 2     3

We can find the rest of the left subtree using the in-order list since we know that the list goes from left subtree to right subtree

Tree:               1
                  /   \
                 2     3
                / \
               4   5

We can do the same for part of the right subtree

Tree:               1
                  /   \
                 2     3
                / \   / \
               4   5 7   8

We only have the 6 to add. We know that 6 must be attached to 7 somehow based on both orderings
We know it must be the left child of 7 because if it was the right child, 6 would be after 7 in the post-order list
Tree:               1
                  /   \
                 2     3
                / \   / \
               4   5 7   8
                    /
                   6
*/

/*
Questions:
1. What does traversal via recursion look like?
2. How can we implement traversals without recursion?
*/

/*
Linked list
struct Node {
    int val;
    Node* next;
}

Node* head;


// Appending a node
Node* ptr = head;

if (head == nullptr) {
    head = new Node(1);
}
else {
    while(ptr->next == nullptr) {
        ptr = ptr->next
    }
}
ptr->next = new Node(10);

// Deleting a node
if (head == nullptr) { return; } // Don't do anythin
Node* ptr = head;
int target;
while (ptr != nullptr) {
    if (ptr->next->val == target) {
        Node* newNext = ptr->next->next;
        delete ptr->next;
        ptr->next = newNext;
        delete toDelete;
    }
}
*/