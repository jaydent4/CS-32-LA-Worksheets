/*
CLARIFICATION FROM LAST WEEK

Copy Constructors
If we do not define a copy constructor, the default copy constructor will call the copy constructor on any data members of a class type (also call the default if this one also is not defined).
However, a copy constructor is most important if you have pointers to class types. The copy constructor does not create new objects if there are pointer data members (remember, pointers are just memory addresses).

If we do not define a copy constructor, we might end up with a structure that looks like this:


    Object 1                                                           Object 2
+-------------+                                                    +-------------+ 
|             |                                                    |             |
|             |               Data Member Object                   |             |
|       ----------------------> +------------+ <--------------------------       |
|             |                 |            |                     |             |
+-------------+                 |            |                     +-------------+
                                |            |
                                |            |
                                +------------+

Implementation-wised, we usually don't want to have two objects point to the same object data member.
*/

// Another Recursion Practice Question (asked by a student)
// Suppose we have an m x n grid and a robot is placed in the top left corner of the grid.
// Our robot can only go DOWN and RIGHT to reach the bottom right corner of the grid
// Return the number of possible paths to reach the bottom right corner of the grid (NOTE: we do not need to actually return the paths, just the number of paths)
// **More difficult than what you will see in this class, but still a good question to learn how to apply recursion in different cases

/*
EX: 2 x 2 grid
+----+----+
| R  |    |
+----+----+
|    |    |
+----+----+

This has two paths
1. Down -> Right
2. Right -> Down
*/

#include <iostream>
#include <cassert>

int countPaths(int m, int n) {
    if (m == 1 || n == 1) { return 1; } // There is only one path to get to a 1 x 1 (we are already at the finish).
    if (m == 0 || n == 0) { return 0; } // There are no possible ways to get to the bottom right corner if we don't have a valid grid.
    int right = countPaths(m, n - 1);
    int down = countPaths(m - 1, n);
    return right + down;
}

// INHERITANCE/POLYMORPHISM

/*
QUESTION 1:

class LivingThing {
    public:
        virtual void intro()
        {
            cout << "I’m a living thing" << endl;
        }
};

class Person : public LivingThing {
    public:
        virtual void intro()
        {
            cout << "I’m a person" << endl;
        }
};

class UniversityAdministrator : public Person {
    public:
        virtual void intro()
        {
            cout << "I’m a university administrator" << endl;
        }
};

class Chancellor : public UniversityAdministrator {
    public:
        virtual void intro()
        {
            cout << "I’m Gene" << endl;
        }
};

int main() {
    LivingThing* thing = new Chancellor();
    thing->intro();
}

We technically only need the "virtual" keyword on class LivingThing but adding virtual on everything does not change the behavior of the program and is much easier to read
*/

/*
QUESTION 2:

#include <iostream>
using namespace std;
class Pet {
    public:
        Pet()  { cout << "Pet" << endl;  }
        ~Pet() { cout << "~Pet" << endl; }
};
  // This is an unusual class that derives from Pet but also
  // contains a Pet as a data member.
class Dog : public Pet {
    public:
        Dog() { cout << "Woof" << endl; }
        ~Dog() { cout << "Dog ran away!" << endl; }
    private:
        Pet buddy;
};

int main() {
    Pet* milo = new Dog;
    delete milo;
}


Pet <= Creates base class for Dog (Pet)
Pet <= Initializing data member "buddy"
Woof <= Execute the body of the constructor
~Pet <= Execute body of the destructor for Pet (note how Dog destructor is never called)

QUESTION 3:
class Pet {
    public:
        Pet() { cout << "Pet" << endl; }
        virtual ~Pet() { cout << "~Pet" << endl; }
};
Suppose we replace the Pet class with this implementation instead.

Pet <= Construct base class for Dog (Pet)
Pet <= Construct buddy
Woof <= Execute the body of the Dog constructor
~Pet <= Call the destructor on buddy
~Pet <= Call the destructor on the base class
};
*/

/*
QUESTION 4:

#include <string>
using namespace std;
class Animal
{
    public:
        Animal(string name);
    private:
        string m_name;
};
Animal::Animal(string name) : m_name(name) {}

class Cat : public Animal
{
    public:
        Cat(string name, int amountOfYarn);
    private:
        int m_amountOfYarn;
};

Cat::Cat(string name, int amountOfYarn) : Animal(name), m_amountOfYarn(amountOfYarn) {}

class Himalayan : public Cat
{
    public:
        Himalayan(string name, int amountOfYarn);
};

Himalayan::Himalayan(string name, int amountOfYarn) : Cat(name, amountOfYarn) {}

class Siamese: public Cat
{
    public:
        Siamese(string name, int amountOfYarn, string toyName);
    private:
        string m_toyName;
};

Siamese::Siamese(string name, int amountOfYarn, string toyName) : Cat(name, amountOfYarn), m_toyName(toyName) {}
*/

/*
QUESTION 5:
class LivingThing {
    public: // changed from private
        int age;
};

class Person : public LivingThing {
    public:
        Person(int a) { age = a; }
        void birthday() {
            age++;
        }
};
*/

/*
QUESTION 6:
#include <iostream>
#include <string>
using namespace std;
class A
{
    public:
        A() : m_val(0)
        {
            cout << "What a wonderful world! " << m_val << endl;
        }
        virtual ~A()
        {
            cout << "Guess this is goodbye " << endl;
        }
        virtual void saySomething() = 0;
        virtual int giveMeSomething() = 0;
    private:
        int m_val;
};

class B : public A
{
    public:
        B() : m_str("me"), m_val(1)
        {
            cout << m_str << " has just been birthed."  << endl;
        }
        B( string str, int val ) : m_str(str), m_val(val)
        {
            cout << "More complex birth " << m_str << endl;
        }
        ~B()
        {
            cout << "Why do I have to leave this world!" << endl;
        }
        virtual void saySomething()
        {
            cout << "Coming in from " << m_str << " with " << giveMeSomething() << endl;
        }
        virtual int giveMeSomething()
        {
            return m_val*5;
        }
    private:
        int m_val;
        string m_str;
};

class C
{
    public:
        C() : m_val(2)
        {
            m_b = new B("C", m_val);
            cout << "Hello World!!" << endl;
        }
        C(const B& b, int val) :  m_val(val)
        {
            m_b = new B(b);
            cout << m_b->giveMeSomething() << endl;
        }
        ~C()
        {
            m_b->saySomething();
            delete m_b;
            cout << "Goodbye world!" << endl;
        }
    private:
        B* m_b;
        int m_val;
};

int main()
{
    B* b_arr = new B[3];
    for(int i = 0; i < 3; i++) {
        b_arr[i].saySomething();
    }
    B b("B", 5);
    A* a = &b;
    cout << a->giveMeSomething() << endl;
    C c;
    C c2(b, b.giveMeSomething());
    delete [] b_arr;
}

ANSWER: (any new lines and comments are not actually printed but are there for clarity)

// new B[3] constructs three B objects
What a wonderful world! 0 // Base class constructor
me has just been birthed. // B constructor
What a wonderful world! 0
me has just been birthed.
What a wonderful world! 0
me has just been birthed.

// b_arr[i].saySomething() 3 times
Coming in from me with 5
Coming in from me with 5
Coming in from me with 5

// Using the overloaded constructor for B
What a wonderful world! 0 // Base class constructor
More Complex birth B // B constructor

// calling giveMeSomething() on a
25 // uses b's giveMeSomething()

// Creating C object
What a wonderful world! // Base class constructor for B in the body C's constructor
More complex birth C // B constructor
Hello World!! // Body of C constructor

// Creating C object using the overloaded constructor
25 // Calling m_b->giveMeSomething() (m_b's object's m_val = 5)

// Deleting array of B
Why do I have to leave this world! // B destructor
Guess this is goodbye // Base class destructor
Why do I have to leave this world!
Guess this is goodbye
Why do I have to leave this world!
Guess this is goodbye

// Destroying all objects in reverse order
// Deleting c2
Coming in from B with 25 // Calling saySomething()
Why do I have to leave this world! // delete m_b
Goodbye world! // printed from body

// Deleting c
Coming in from C with 10 // m_b->saySomething()
Why do I have to leave this world! // delete m_b
Goodbye world!

// Deleting b
Why do I have to leave this world! // B destructor
Guess this is goodbye // Base class destructor
*/

// TEMPLATE/STL PROBLEMS

/*
QUESTION 1

class Potato {
    public:
        Potato(int in_size) : size(in_size) { }
        int getSize() const {
            return size;
        }
    private:
        int size;
};
int main() {
    vector<Potato> potatoes;
    Potato p1(3);
    potatoes.push_back(p1);
    potatoes.push_back(Potato(4));
    potatoes.push_back(Potato(5));
    vector<Potato>::iterator it = potatoes.begin(); // 1
    while (it != potatoes.end()) {
        it = potatoes.erase(it);  // 2
        it++;
    }
    for (it = potatoes.begin(); it != potatoes.end(); it++) {
        cout << it->getSize() << endl;  // 3
    }
}
ANSWER:
1. int Potatoes (two types)
2. erase returns an iterator to the next item, iterators are also invalidated when we delete something so iterating it will not work
3. iterators use pointer syntax
*/

/*
QUESTION 2:
#include <iostream>
template <typename T>
T max(T x, T y)
{
    return (x > y) ? x : y;
}
int main()
{
    std::cout << max(3, 7) << std::endl;     // line 1
    std::cout << max(3.0, 7.0) << std::endl; // line 2
    std::cout << max(3, 7.0) << std::endl;   // line 3
}

Third line will not compile. The implementation of max is most likely structure as follows:

template <typename T>
T max(T a, T b) {...}

Even though a and b use template type T, both must be the same type.
*/

/*
class Potato {
    public:
        Potato(int in_size) : size(in_size) { }
        int getSize() const {
            return size;
        }
    private:
    int size;
};
int main() {
    set<Potato> potatoes;  // 1
    Potato p1(3);
    Potato p2(4);
    Potato p3(5);
    potatoes.insert(p1);
    potatoes.insert(p2);
    potatoes.insert(p3);
    set<Potato>::iterator it = potatoes.begin();
    while (it != potatoes.end()) {
        it = potatoes.erase(it);  // 2
    }
    for (it = potatoes.begin(); it != potatoes.end(); it++) {
        cout << it->getSize() << endl;  // 3
    }
}
1. when initializing a set with a class type, you need to define a operator< for the class
EXAMPLE operator<:

    bool operator<(const Potato& a, const Potato& b) {
        return a.getSize() < b.getSize();
    }

2. Erase invalidates the iterator, erase returns the next iterable
3. Iterators use pointer syntax
*/

#include <set>
#include <list>
using namespace std;

int deleteOddSumLists(set<list<int>*>& s) {
    int numDeleted = 0;
    set<list<int>*>::iterator set_iter = s.begin();
    while (set_iter != s.end()) {
        int sumList = 0;
        list<int>::iterator list_iter = (*set_iter)->begin();
        while (list_iter != (*set_iter)->end()) {
            sumList += *list_iter;
            list_iter++;
        }

        if (sumList % 2 == 0) {
            set_iter++;
        }
        else {
            delete *set_iter;
            set_iter = s.erase(set_iter);
            numDeleted++;
        }
    }
    return numDeleted;
}

int main()
{
    set<list<int>*> s;
    list<int>* l1 = new list<int>;
    l1->push_back(1);
    l1->push_back(2);
    list<int>* l2 = new list<int>;;
    l2->push_back(1);
    l2->push_back(1);
    list<int>* l3 = new list<int>;;
    l3->push_back(1);
    l3->push_back(0);
    s.insert(l1);
    s.insert(l2);
    s.insert(l3);
    cout << deleteOddSumLists(s) << endl;

    // TEST CASES FOR COUNTPATHS
    assert(countPaths(2, 2) == 2);
    assert(countPaths(3, 2) == 3);
    assert(countPaths(2, 3) == 3);
    assert(countPaths(3, 7) == 28);
    std::cout << "ALL TEST CASES PASSED" << std::endl;
}

/*
QUESTIONS:
1. Why might inheritance be useful?
2. Why might templates be useful?
*/