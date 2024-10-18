// Time Complexity Questions
/*
int randomSum(int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(rand() % 2 == 1) {
                sum += 1;
            }
            for(int k = 0; k < j * i; k += j) {
                if(rand() % 2 == 2) {
                    sum += 1;
                }
            }
        }
    }
    return sum;
}

Solution: 

int operationFoo(int n, int m, int w) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = m; j > 0; j /= 2) {
            for (int jj = 0; jj < 50; jj++) {
                for (int k = w; k > 0; k -= 3) {
                    res += i*j + k;
                }
            }
        }
    }
}

Solution: 


int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] == x)
            return middle;
        else if (arr[middle] < x)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1
}

Solution: 


bool isPrime(int n) {
    if (n < 2 || n % 2 == 0) return false;
    if (n == 2) return true;
    for (int i = 3; (i * i) <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

Solution:
*/

// Linked List Questions

#include <iostream>
#include <string>
#include <cassert>

// CLASS NODE DECLARATIONS
// For integer values
class Node {
    public:
        Node(int value);
        ~Node();
        int getData() const;
        void setData(int value);
        Node* getNext() const;
        void setNext(Node* node);
    private:
        int data;
        Node* next;
};

Node::Node(int value) : data(value), next(nullptr) {}

Node::~Node() { if (next != nullptr) delete next; }

int Node::getData() const { if (this != nullptr) return data; else return -999999; }

void Node::setData(int value) { if (this != nullptr) data = value; }

Node* Node::getNext() const { if (this != nullptr) return next; else return nullptr; }

void Node::setNext(Node* node) { if (this != nullptr) next = node; }

// For character values
class Node_c {
    public:
        Node_c(char value);
        ~Node_c();
        char getData() const;
        void setData(char value);
        Node_c* getNext() const;
        void setNext(Node_c* node);
    private:
        char data;
        Node_c* next;
};

Node_c::Node_c(char value) : data(value), next(nullptr) {}

Node_c::~Node_c() { if (next != nullptr) delete next; }

char Node_c::getData() const { if (this != nullptr) return data; else return '\0'; }

void Node_c::setData(char value) { if (this != nullptr) data = value; }

Node_c* Node_c::getNext() const { if (this == nullptr) return nullptr; else return next; }

void Node_c::setNext(Node_c* node) { if (this != nullptr) next = node; }

int cmpr(Node* head, int* arr, int arr_size) {

}

int compare(Node_c* list1, Node_c* list2) {

}

// FUNCTIONS FOR TESTING
template<class T, class ValueType>
T* generateLL(ValueType a[], int n) {
    if (n == 0) { return nullptr; }
    T* start = new T(a[0]);
    T* current = start;
    for (int i = 1; i < n; i++) {
        T* newNode = new T(a[i]);
        current->setNext(newNode);
        current = current->getNext();
    }
    return start;
}

template<class T>
void printLL(T* LL) {
    T* current = LL;
    while (current != nullptr) {
        std::cout << current->getData() << " -> "; 
        current = current->getNext();
    }
    std::cout << std::endl;
}

const int QUESTION = 1;

int main() {
    // Question 1
    int test1[3] = {1, 2, 3};
    int n1 = 3;
    int test2[5] = {1, 2, 3, 4, 5};
    int n2 = 5;
    int test3[6] = {1, 2, 4, 8, 16, 32};
    int n3 = 6;
    int test4[2] = { -1, 0 };
    int n4 = 2;
    Node* test1LL = generateLL<Node, int>(test1, n1);
    Node* test2LL = generateLL<Node, int>(test2, n2);
    Node* test3LL = generateLL<Node, int>(test3, n3);
    Node* test4LL = generateLL<Node, int>(test4, n4);

    // Question 2
    char word1[11] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
    int word1len = 11;
    char word2[5] = {'H', 'e', 'l', 'l', 'o'};
    int word2len = 5;
    char word3[4] = {'c', 's', '3', '2'};
    int word3len = 4;
    char word4[6] = {'e', 'c', 'e', 'm', '1', '6'};
    int word4len = 6;
    Node_c* word1LL = generateLL<Node_c, char>(word1, word1len);
    Node_c* word2LL = generateLL<Node_c, char>(word2, word2len);
    Node_c* word3LL = generateLL<Node_c, char>(word3, word3len);
    Node_c* word4LL = generateLL<Node_c, char>(word4, word4len);

    switch(QUESTION) {
        case 1:
            assert(cmpr(test1LL, test2, n2) == 2);
            assert(cmpr(test2LL, test3, n3) == 1);
            assert(cmpr(test1LL, test4, n4) == -1);
            assert(cmpr(test2LL, test2, n2) == 4);
            break;
        case 2:
            assert(compare(word1LL, word2LL) > 0);
            assert(compare(word3LL, word4LL) < 0);
            assert(compare(word1LL, word1LL) == 0);
            break;
        default:
            assert(cmpr(test1LL, test2, n2) == 2);
            assert(cmpr(test2LL, test3, n3) == 1);
            assert(cmpr(test1LL, test4, n4) == -1);
            assert(cmpr(test2LL, test2, n2) == 4);
            assert(compare(word1LL, word2LL) > 0);
            assert(compare(word3LL, word4LL) < 0);
            assert(compare(word1LL, word1LL) == 0);
            break;
    }
    std::cout << "All Test Cases Passed" << std::endl;
    delete test1LL;
    delete test2LL;
    delete test3LL;
    delete test4LL;
    delete word1LL;
    delete word2LL;
    delete word3LL;
    delete word4LL;
}