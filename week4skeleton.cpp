#include <stack>
#include <queue>
#include <string>

// Since there is no definition for cs32::stack or cs32::queue (I didn't have the code to do it), you can use the std library stack and queue std::stack and std::queue (covered a bit later in the class)
/*
To define each of them
std::stack<TYPE> NAME;
std::queue<TYPE> NAME;
^            ^
|            |
std lbrary   |
             |
    this is called a template (covered later in the class). To initialize a stack of integers, you would declare it as "std::stack<int> stackOfInts;"
*/

bool isValid(std::string symbols) {

}

void reverseQueue(std::queue<int> q) {

}

class SectionStack {
    public:
        SectionStack();
        bool isEmpty();
        void empty();
        void push(int value);
        int top();
        void pop();
    private:
        int placeholder;
};

SectionStack::SectionStack() { placeholder = 0; }

bool SectionStack::isEmpty() { return; }

void SectionStack::empty() {
    return;
}

void SectionStack::push(int value) {
    return;
}

int SectionStack::top() { return -1; }

void SectionStack::pop() { return; }