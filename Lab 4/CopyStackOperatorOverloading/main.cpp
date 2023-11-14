#include <iostream>

using namespace std;

class Stack
{
    int top ;
    int  _size;
    int* arr ;
public:
    // Default Constructor
    Stack()
    {
        top = -1 ;
        _size = 10 ;
        arr = new int[_size] {0};
    };
    Stack(int user_size)
    {
        top = -1 ;
        this->_size = user_size ;
        arr = new int[_size] {0};
    };
    // Destructor
    ~Stack()
    {
        delete[] arr;
    }

    void push(int data)
    {
        if(top < _size-1)
        {
            top++ ;
            arr[top] = data;
        }
        else
        {
            cout<<"Out of range" ;
        }
    };
     // Copy Operator Overloading
     Stack& operator = (Stack & s){
            this-> top=s.top;
            this-> _size=s._size;
            delete[] arr;//delete

            arr=new int[_size];//rellaction

            for(int i=0; i<=top; i++){
                arr[i]=s.arr[i];
            }
            return *this;
        }
    int pop(void)
    {
        if(top >= 0)
        {
            int popped_value = arr[top];
            cout << "deleted num: " << popped_value << endl;
            top--;

            return popped_value;
        }
        else
        {
            cout << "Empty" << endl;

        }
    }
    void display_stack()
    {
        for(int i = 0 ; i <= top ; i++ )
        {
            cout<< arr[i]<<endl;
        }
    }
};//end class

int main()
{
    Stack s(10);
    Stack s1(10);
    s.push(1);
    s.push(5);
    s.push(6);


    s1 = s;
    cout<< "New s1" ;
    s1.display_stack();



    return 0;
}
