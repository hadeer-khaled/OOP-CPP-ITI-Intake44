#include <iostream>

using namespace std;

class Stack
{
    int top ;
    int  _size;
    int* arr ;
    public:
        Stack()
        {
            top = -1 ;
            _size = 10 ;
            arr = new int[_size]{0};
        };
        Stack(int user_size)
        {
            top = -1 ;
            this->_size = user_size ;
            arr = new int[_size]{0};
        };

        ~Stack(){}
        void push(int data){
            if(top < _size-1){
                top++ ;
                arr[top] = data;
            }
            else {
                cout<<"Out of range" ;
            }
        };
        /*int pop(void){
            if(top !=-1){
                int popped_value = arr[top];
                cout<< "deleted num: " << popped_value <<endl;
                top--;

                return popped_value ;
            }
            else{
                cout<< "Empty" <<endl;
            }
        } ;*/
        int pop(void){
    if(top >= 0){
        int popped_value = arr[top];
        cout << "deleted num: " << popped_value << endl;
        top--;

        return popped_value;
    }
    else {
        cout << "Empty" << endl;

    }
}

        void display_stack(){
            for(int i = 0 ; i <= top ; i++ ){
                cout<< arr[i]<<endl;
            }
        }
};//end class

int main()
{
Stack s(10);
s.pop() ; //empty
s.push(1);
s.push(5);
s.push(6);
s.pop() ;//1
s.pop() ;//5;
s.push(7);
s.pop() ;//6;
s.pop() ;//7;
s.pop() ;//Empty;
s.push(7);
s.pop() ;//7 ;



    s.display_stack();
    cout << "Hello world!" << endl;
    return 0;
}
