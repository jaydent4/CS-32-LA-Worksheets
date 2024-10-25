#include <stack>
#include <queue>
#include <string>

bool isValid(std::string symbols) {
    std::stack<int> unpaired; // Used <stack> instead of cs32::Stack, but implementation stays the same
    for (int i = 0; i < symbols.length(); i++) {
        char c = symbols[i];
        switch (c) {
            case '(':
            case '[':
                unpaired.push(c);
                break;
            case ')':
                if ( unpaired.empty() || unpaired.top() != '(' ) { return false; }
                unpaired.pop();
                break;
            case ']':
                if ( unpaired.empty() || unpaired.top() != '[' ) { return false; }
                unpaired.pop();
                break;
        }
    }
    return unpaired.empty();
}

void reverseQueue(std::queue<int> q) {
    std::stack<int> s; // Used <stack> instead of cs32::Stack, but implementation stays the same
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

/*
Postfix notation follows the following form:

             Postfix                 Infix (what we use)
    operand1 operand2 operator => operand1 operator operand2

Following this ordering, we can evalutate the expression

9 5 * 8 - 6 7 * 5 3 - / *   ==> look at first operator and previous two operands: 9 5 * => 9 * 5 = 45, place 45 in place of 9 5 *

45 8 - 6 7 * 5 3 - / *      ==> look at the next operator and previous two operands: 45 8 - => 45 - 8 = 37, place 37 in place of 45 8 -

37 6 7 * 5 3 - / *

In this case, we have three consecutive operands. Notice how we only perform an operation when we see an operator. We will still follow the same convention even if we have three consecutive numbers.

37 6 7 * 5 3 - / *          ==> look at the next operator (*) and the two previous operands (6, 7), 6 * 7 = 42, replace 6 7 * with 42

37 42 5 3 - / *             ==> 5 3 - => 5 - 3 = 2

37 42 2 / *                 ==> 42 2 / => 42 / 2 = 21

37 21 *                     ==> 37 21 * => 37 * 21 = 777

777

Once we reach a single number, the expression is solved.
If we were to implement this in a program, we would use a stack. We need to be able to access the two previous values for each expression, which will be on the top of the stack.
*/

class SectionStack {
    public:
        SectionStack();
        bool isEmpty();
        void empty();
        void push(int value);
        int top();
        void pop();
    private:
        std::queue<int> q;
        int size; 
};

SectionStack::SectionStack() : size(0) {}

bool SectionStack::isEmpty() { return (size == 0); }

void SectionStack::empty() {
    while (size) {
        q.pop();
        size--;
    }
}

void SectionStack::push(int value) {
    q.push(value);
    for (int i = 0; i < size; i++) {
        q.push(q.front());
        q.pop();
    }
    size++;
}

int SectionStack::top() { return q.front(); }

void SectionStack::pop() { q.pop(); }

// NOTE: You can also implement this if you just push the value on the queue in your push() function. However, both pop() and top() implementations require for loops to obtain the last item in the queue (more inefficient)

/*
QUESTIONS:
1. In what cases would you want to use a stack and a queue?
2. MORE ADVANCED TOPIC

Suppose you are given the following algorithm to solve a maze represented by a 2D array using either a stack or queue (labeled as DATA_STRUCTURE):

    push start (i, j) into the DATA_STRUCTURE
    while DATA_STRUCTURE is not empty
        pop DATA_STRUCTURE and save the coordinate
        mark the coordinate as seen
        push (i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1) onto DATA_STRUCTURE if the new coordinate has not been seen and is within the bounds of the maze

What are the differences in the pathing of the algorithm between choosing a stack or queue as DATA_STRUCTURE?
    
*/

