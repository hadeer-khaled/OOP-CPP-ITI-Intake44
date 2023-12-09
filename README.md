# Object-Oriented Programming (OOP) with C++ Course

## Course Overview

In this comprehensive course, I've gained a deep understanding of fundamental and advanced concepts in C++ programming, focusing on Object-Oriented Programming (OOP) principles. The lectures are structured to provide a robust foundation in OOP and cover various essential features of the C++ programming language. Each topic is presented with practical examples to enhance learning and application.

## Lecture 1: Paradigms and C/C++ Differences

- **Paradigms:**
  - Discusses the paradigms of programming, focusing on the transition from procedural to object-oriented.
  
- **Difference between C and C++:**
  - Highlights the distinctions between C and C++, including the shift from structs to classes.
  
- **Memory Management: malloc, new:**
  - Covers memory allocation in C using `malloc` and in C++ using `new`.
  
- **Pointers, References:**
  - Explains pointers and references, showcasing their usage in C and C++.
  
- **Class Syntax and Access Modifiers (Encapsulation):**
  - Introduces class syntax and access modifiers, emphasizing encapsulation.
  
- **Member Function and Standalone Function:**
  - Demonstrates member functions and standalone functions within a class.
  
- **Friend Function:**
  - Explains friend functions, showcasing their role in accessing private members.
    
------------------------------------------------------------

# Lecture 2: Advanced C++ Concepts

## `this` Keyword

The `this` keyword in C++ is a special pointer that refers to the current instance of a class. It is an implicit parameter available within the member functions of a class.

### Notes:

- Using the `this` keyword is optional in most cases. However, it can be helpful to explicitly use `this` to improve code clarity and avoid ambiguity when there is a naming conflict between local variables and member variables.

- There are four ways the `this` keyword can be used in a class in C++:
  1. Resolve Shadowing Issue Using `this` Keyword.
  2. Access Currently Executing Object Using `this` Keyword (used to chain functions and delete objects).
  3. Access Data Members Using `this` Keyword.
  4. Calling Member Functions Using `this` Keyword.

### Examples:

#### 1. Resolve Shadowing Issue Using `this` Keyword

```cpp 
#include<iostream>
using namespace std;

class Test {
private:
    int x;

public:
    void setX(int x) {
        // The 'this' pointer is used to retrieve the object's x
        this->x = x; // hidden by the local variable 'x'
    }
};
```
#### 2. Access Currently Executing Object Using this Keyword
**Method Chaining using this** 

Method chaining is a common syntax for invoking multiple method calls in object-oriented programming languages. Each method returns an object, allowing the calls to be chained together in a single statement without requiring variables to store the intermediate results.

```cpp
#include<iostream>
using namespace std;

class Test {
private:
    int x;
    int y;

public:
    Test(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    Test setX(int a) {
        x = a;
        return *this;
    }
    Test setY(int b) {
        y = b;
        return *this;
    }
};

int main() {
    Test obj1;
    obj1.setX(10).setY(20);
    obj1.print();
    return 0;
}

```
-------------------------------------------------------------
# Lecture 3: Constructors and Destructors

## Topics Covered:

- Constructors & Destructors: Deep dive into constructors and destructors.
- Copy Constructor: Understanding the copy constructor and when to use it, discussing shallow copy and deep copy.

## Constructors in C++

Constructor in C++ is a special method that is invoked automatically at the time of object creation. It is used to initialize the data members of new objects generally.

- Constructor is a member function of a class, whose name is the same as the class name.
- It is a special type of member function that initializes the data members for an object of a class automatically when an object of the same class is created.
- Constructor is invoked at the time of object creation, providing data for the object, which is why it is known as a constructor.

### Characteristics of the Constructor:

- The name of the constructor is the same as its class name.
- Constructors are mostly declared in the public section of the class, though they can be declared in the private section of the class.
- Constructors do not return values; hence they do not have a return type.
- A constructor gets called automatically when we create the object of the class.
- Constructors can be overloaded.
- Constructor cannot be declared virtual.
- Constructor cannot be inherited.
- Constructors make implicit calls to new and delete operators during memory allocation.
- If we do not specify a constructor, the C++ compiler generates a default constructor for an object (expects no parameters and has an empty body).

## Example:

```cpp
class MyClass {
public:
    // Default Constructor
    MyClass() {
        cout << "Default Constructor Called" << endl;
    }
    // Parameterized Constructor
    MyClass(int value) {
        cout << "Parameterized Constructor Called with value: " << value << endl;
    }
    // Destructor
    ~MyClass() {
        cout << "Destructor Called" << endl;
    }
};

int main() {
    // Creating objects and demonstrating constructor calls
    MyClass obj1;       // Default Constructor Called
    MyClass obj2(42);  // Parameterized Constructor Called with value: 42

    // Destructor will be called when the scope is exited
    return 0;
}
```
-----------------------------------------------------

# Lecture 4: Operator Overloading

### Operator Overloading in Complex Numbers Class

In C++, operators can be overloaded to work with user-defined data types. Let's explore some examples of operator overloading in a Complex Numbers class.

```cpp
#include<iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overloading the + operator
    Complex operator+(const Complex &c) {
        Complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }
    // Overloading prefix ++ operator
    Complex operator++() {
        ++real;
        ++imaginary;
        return *this;
    }

    // Overloading postfix ++ operator
    Complex operator++(int) {
        Complex temp = *this;
        ++real;
        ++imaginary;
        return temp;
    }
    // Overloading [] operator
        int Complex::operator[](int index) {
        if (index == 0) {
            return real;
        } else if (index == 1) {
            return imaginary;
        } else {
            // Handle out-of-bounds key
            cout << "Error: Invalid index for Complex number." << endl;
            return -1000000
        }
    }
    // Overloading [] operator (takes string)
    int& Complex::operator[](const string& key) {
        if (index == "key") {
            return real;
        } else if (index == "key") {
            return imaginary;
        } else {
            // Handle invalid key 
            cout << "Error: Invalid key for Complex number." << endl;
           return -1000000
        }
    }
    // Friend function declarations
    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);

    // Display the complex number
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }

};
// Overloading >> operator for input
istream& operator>>(istream& in, Complex& c) {
    cout << "Enter Real part: ";
    in >> c.real;
    cout << "Enter Imaginary part: ";
    in >> c.imaginary;
    return in;
}

// Overloading << operator for output
ostream& operator<<(ostream& out, const Complex& c) {
    out << "Real: " << c.real << ", Imaginary: " << c.imaginary;
    return out;
}
```
---------------------------------------------------------------
# Lecture 5: OOP Relationships
- **Composition (Part of):**
Composition represents a "part-of" relationship, where one class is composed of another. In this example, a `Car` class is composed of an `Engine`.
```cpp
// Composition example
class Engine {
    // Engine class definition
};

class Car {
    Engine carEngine; // Composition
};
```
- **Association (Deal With):**
Association represents a "deal-with" relationship, where two classes are associated with each other. 
In this example, a `Student` class is associated with a `Course` class
```cpp
// Association example
class Student {
    // Student class definition
};
class Course {
    // Course class definition
};
void enrollStudentInCourse(Student* student, Course* course) {
    // Association (Deal with)
}
``` 
- **Aggregation (Has a):**
Aggregation represents a "has-a" relationship, where one class has another as a part, but the part can exist independently. In this example, a `University` class has a `Department` as part of it.
```cpp
class Department {
    private:
    string departmentName;
    public:
        Department(string name) : departmentName(name) {}

        void displayInfo() {
            cout << "Department: " << departmentName << endl;
        }
};
class University {
    private:
    string universityName;
    Department* department;
    public:
        University(string name) : universityName(name), department(nullptr) {}

        void associateDepartment(Department* dept) {
            department = dept;
        }
        void displayInfo() {
            cout << "University: " << universityName << endl;
            if (department != nullptr) {
                department->displayInfo();
            } else {
                cout << "No associated department." << endl;
            }
        }
};
int main() {
    Department computerScience("Computer Science");
    University myUniversity("Example University");

    myUniversity.associateDepartment(&computerScience);
    myUniversity.displayInfo();

    return 0;
}
```
--------------------------------------------------------
# Lecture 6: Inheritance
- **Inheritance (Is a):**
Covers the concept of inheritance, where one class inherits from another.
```cpp
// Inheritance example
class Animal {
    // Animal class definition
};

class Dog : public Animal {
    // Dog inherits from Animal
};
``` 

- **Fake Overriding:**
Introduces fake overriding and its implications.
``` cpp
// Fake overriding example
class Base {
public:
    void display() {
        cout << "Base class display" << endl;
    }
};

class Derived : public Base {
public:
    void display(int x) {
        cout << "Derived class display" << endl;
    }
};
``` 

-------------------------------------------------------
# Lecture 7: Polymorphism and Abstraction
- **Polymorphism (Overriding):**
Explores polymorphism through function overriding using `virtual` keyword.
```cpp
// Polymorphism example
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a circle" << endl;
    }
};
``` 
- **Abstraction:**
Discusses abstraction and its role in simplifying complex systems.

``` cpp
// Abstraction example
class Database {
public:
    virtual void query() = 0; // Pure virtual function
};

class MySQLDatabase : public Database {
public:
    void query()  {
        cout << "Executing MySQL query" << endl;
    }
};
``` 
----------------------------------------------------------
# Lecture 8: Advanced Topics
- **Type of Inheritance (Single, Multiple, Multilevel, Hierarchical [Diamond]):**

1) Single Inheritance
 
```cpp 
class Animal {
public:
    void eat() {
        cout << "Animal is eating." << endl;
    }
};
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking." << endl;
    }
};

```
2) Multiple Inheritance
 
```cpp 
class A {
public:
    void displayA() {
        cout << "Class A" << endl;
    }
};

class B {
public:
    void displayB() {
        cout << "Class B" << endl;
    }
};

class C : public A, public B {
public:
    void displayC() {
        cout << "Class C" << endl;
    }
};
```
3) Hierarchical Inheritance (Diamond)
 
```cpp 
#include <iostream>
using namespace std;

class A {
public:
    void display() {
        cout << "This is display function." << endl;
    }
};
class B : virtual public A {
public:
    void display() {
        cout << "This is display function." << endl;
    }
};
class C : virtual public A {
public:
    void display() {
        cout << "This is display function." << endl;
    }
};
class D : public B, public A {
public:
    void display() {
        cout << "This is display function." << endl;
    }
};
```
- **Static Variable:**
Covers the usage of static variables within a class.
```cpp 
class Counter {
public:
    static int count;  // Static variable

    Counter() {
        count++;
    }

    void displayCount() {
        cout << "Count: " << count << endl;
    }
};
int Counter::count = 0;  // Initializing static variable

int main() {
    Counter obj1, obj2, obj3;
    obj1.displayCount();  // Count: 3
    obj2.displayCount();  // Count: 3
    return 0;
}

```
- **Template:**
Introduces templates for generic programming.
Exception Handling:
```cpp 
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add(5, 10) << endl;        // Output: 15
    cout << add(3.5, 2.5) << endl;     // Output: 6
    cout << add("Hello", " World") << endl;  // Output: Hello World
    return 0;
}
```
- **Exception handling mechanisms in C++.**
```cpp 
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 0;

    try {
        if (b == 0) {
            throw "Division by zero!";
        }
        cout << "Result: " << a / b << endl;
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }

    return 0;
}
```
- **Mode of Inheritance:**
1. Public.
2. Protected.
3. Private.
``` cpp
#include <iostream>
using namespace std;

// Base class with different access specifiers
class Base {
public:
    void publicFunction() {
        cout << "Public function in Base class." << endl;
    }

protected:
    void protectedFunction() {
        cout << "Protected function in Base class." << endl;
    }

private:
    void privateFunction() {
        cout << "Private function in Base class." << endl;
    }
};

// Public inheritance
class PublicDerived : public Base {
public:
    void accessBaseFunctions() {
        publicFunction();    // Accessible
        protectedFunction(); // Accessible (due to protected inheritance)
        // privateFunction(); // Not accessible
    }
};

// Protected inheritance
class ProtectedDerived : protected Base {
public:
    void accessBaseFunctions() {
        publicFunction();    // Accessible
        protectedFunction(); // Accessible
        // privateFunction(); // Not accessible
    }
};

// Private inheritance
class PrivateDerived : private Base {
public:
    void accessBaseFunctions() {
        publicFunction();    // Accessible
        protectedFunction(); // Accessible
        // privateFunction(); // Not accessible
    }
};

int main() {
    PublicDerived publicObj;
    publicObj.accessBaseFunctions(); // Accessible through public inheritance

    ProtectedDerived protectedObj;
    // protectedObj.accessBaseFunctions(); // Not accessible outside the derived class

    PrivateDerived privateObj;
    // privateObj.accessBaseFunctions(); // Not accessible outside the derived class

    return 0;
}
```

# Acknowledgments

I would like to express my gratitude to [Mina Nagy](https://www.linkedin.com/in/mina-iotsoftwareengineer/) for his explanation and his ability to make the complicated concepts of OOP with C++ both understandable and enjoyable.

