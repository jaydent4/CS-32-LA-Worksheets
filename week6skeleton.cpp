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
    return -1;
}

// INHERITANCE/POLYMORPHISM

/*
QUESTION 1:

class LivingThing {
    public:
        void intro()
        {
            cout << "I’m a living thing" << endl;
        }
};

class Person : public LivingThing {
    public:
        void intro()
        {
            cout << "I’m a person" << endl;
        }
};

class UniversityAdministrator : public Person {
    public:
        void intro()
        {
            cout << "I’m a university administrator" << endl;
        }
};

class Chancellor : public UniversityAdministrator {
    public:
        void intro()
        {
            cout << "I’m Gene" << endl;
        }
};

int main() {
    LivingThing* thing = new Chancellor();
    thing->intro();
}
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

QUESTION 3:
class Pet {
    public:
        Pet() { cout << "Pet" << endl; }
        virtual ~Pet() { cout << "~Pet" << endl; }
};
Suppose we replace the Pet class with this implementation instead.

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

class Cat : public Animal
{
    public:
        Cat(string name, int amountOfYarn);
    private:
        int m_amountOfYarn;
};

class Himalayan : public Cat
{
    public:
        Himalayan(string name, int amountOfYarn);
};

class Siamese: public Cat
{
    public:
        Siamese(string name, int amountOfYarn, string toyName);
    private:
        string m_toyName;
};

*/

/*
QUESTION 5:
class LivingThing {
    private:
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
    vector<int>::iterator it = potatoes.begin(); // 1
    while (it != potatoes.end()) {
        it = potatoes.erase(it);  // 2
        it++;
    }
    for (it = potatoes.begin(); it != potatoes.end(); it++) {
        cout << it.getSize() << endl;  // 3
    }
}

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
    set<Potato> potatoes;
    Potato p1(3);
    Potato p2(4);
    Potato p3(5);
    potatoes.insert(p1);
    potatoes.insert(p2);
    potatoes.insert(p3);
    set<Potato>::iterator it = potatoes.begin();
    while (it != potatoes.end()) {
        it = potatoes.erase(it);
        it++;
    }
    for (it = potatoes.begin(); it != potatoes.end(); it++) {
        cout << it.getSize() << endl;
    }
}
*/

#include <set>
#include <list>
using namespace std;

int deleteOddSumLists(set<list<int>*>& s) {
    return -1;
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