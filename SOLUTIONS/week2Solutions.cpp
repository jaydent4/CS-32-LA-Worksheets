// CODE READING

// QUESTION 1
/*
What is the output of the following code?

class A {
    public:
    A() {
        cout << "DC" << endl;
    }
    A(const A& other) {
        cout << "CC" << endl;
    }
    A& operator=(const A& other) {
        cout << "AO" << endl; return *this
    }
    ~A() {
        cout << "Destructor!" << endl;
    }
};

int main() {
    A arr[3];           =>  prints 3 "DC" for three objects
    arr[0] = arr[1];    =>  prints "AO" for calling assignment operator
    A x = arr[0];       =>  prints "CC" for calling copy constructor
    x = arr[1];         =>  print "AO" for calling assignment operator
    A y(arr[2]);        => print "CC" for calling copy constructor
    cout << "DONE" << endl;
}   

FOLLOWING EXECUTION OF main(): call destructor on all objects
    => "Destructor!"
    => "Destructor!"
    => "Destructor!"
    => "Destructor!"
    => "Destructor!"

ANSWER:
DC
DC
DC
AO
CC
AO
CC
Done
Destructor!
Destructor!
Destructor!
Destructor!
Destructor!
*/

// QUESTION 2
/*
Find four errors in the following code.

class Account {
    public:
        Account(int x) {
            cash = x;
        }
        int cash;
}

class Billionaire {
    public:
        Bilionaire(string n) {
            offshore = Account(1000000000)
            name = n
        }
        Account account;
        Account* offshore;
        string name;
};

int main() {
    Billionaire jin = Billionaire("Jimmy");
    cout << jin.name << " has " << jim.account.cash + jim.offshore->cash << endl;
}

1. Missing semicolon after class Account
2. Needs to assign account with a value
3. Missing "new" keyword for offshore acount
4. Needs destructors

UPDATED CODE:
class Account {
    public:
        Account(int x) {
            cash = x;
        }
        int cash;
};

class Billionaire {
    public:
        Billionaire(string n) : account(100000) {
            offshore = new Account(1000000000)
            name = n
        }

        ~Billionaire() {
            delete offshore
        }
        Account account;
        Account* offshore;
        string name;
};

int main() {
    Billionaire jin = Billionaire("Jimmy");
    cout << jin.name << " has " << jim.account.cash + jim.offshore->cash << endl;
}
*/

// RECURSION QUESTIONS
#include <string>
#include <iostream>
#include <cassert>

int getMax(int a[], int n) {
    if (n == 1) { return a[0]; }
    int rest = getMax(a, n - 1);
    if (a[n - 1] > rest) {
        return a[n - 1];
    }
    return rest;
}

int sumOverThreshold(int x[], int length, int threshold) {
    if (threshold < 0) {
        return 0;
    }
    if (length == 0) {
        return -1;
    }
    int rest = sumOverThreshold(x + 1, length - 1, threshold - x[0]);
    if (rest == -1) {
        return -1;
    }
    return x[0] + rest;
}

std::string endX(std::string str) {
    if (str.length() <= 1) {
        return str;
    }
    if (str[0] == 'x') {
        return endX(str.substr(1)) + 'x';
    }
    return str[0] + endX(str.substr(1));
}

bool isSolvable(int x, int y, int c) {
    if (c == 0) {
        return true;
    }
    if (c < 0) {
        return false;
    }
    return isSolvable(x, y, c - x) || isSolvable(x, y, c - y);
}

// Change QUESTION to test a different question
const int QUESTION = 1;

int main() {
    int arr1[4] = {0, 3, 5, 10};
    int arr2[6] = {10, 4, 2, 4, 2, 10};
    int arr3[5] = {-5, -2, -100, -1, -3};
    int arr4[1] = {1000};

    switch(QUESTION) {
        case 1:
            assert(getMax(arr1, 4) == 10);
            assert(getMax(arr2, 6) == 10);
            assert(getMax(arr3, 5) == -1);
            assert(getMax(arr4, 1) == 1000);
            break;
        case 2:
            assert(sumOverThreshold(arr1, 4, -1) == 0);
            assert(sumOverThreshold(arr2, 6, 14) == 16);
            assert(sumOverThreshold(arr4, 1, 10000) == -1);
            break;
        case 3:
            assert(endX("xrxe") == "rexx");
            assert(endX("xcxsx3x2xixsxcxoxoxlx") == "cs32iscoolxxxxxxxxxxx");
            assert(endX("xxxaaa") == "aaaxxx");
            break;
        case 4:
            assert(isSolvable(7, 5, 45) == true);
            assert(isSolvable(100, 100, 0) == true);
            assert(isSolvable(9, 23, 112) == false);
            break;
        default:
            assert(getMax(arr1, 4) == 10);
            assert(getMax(arr2, 6) == 10);
            assert(getMax(arr3, 5) == -1);
            assert(getMax(arr4, 1) == 1000);
            assert(sumOverThreshold(arr1, 4, -1) == 0);
            assert(sumOverThreshold(arr2, 6, 14) == 16);
            assert(sumOverThreshold(arr4, 1, 10000) == -1);
            assert(endX("xrxe") == "rexx");
            assert(endX("xcxsx3x2xixsxcxoxoxlx") == "cs32iscoolxxxxxxxxxxx");
            assert(endX("xxxaaa") == "aaaxxx");
            assert(isSolvable(7, 5, 45) == true);
            assert(isSolvable(100, 100, 0) == true);
            assert(isSolvable(9, 23, 112) == false);
    }
    
    std::cout << "Passed all test cases." << std::endl;
}


/*
QUESTIONS:
1. Why do you define constructors and destructors?
2. When is recursion useful?
3. Why is recursion often times inefficient?
*/