#include <iostream>
using namespace std;
class Queue
    {
        int _size ;
        int* arr ;
        int head;
        int tail ;
        public:
        Queue()
        {
            head = -1, tail = -1;
            _size = 10 ;
            arr = new int[_size]{0};
        }
        Queue(int user_size)
        {
            _size = user_size ;
            arr = new int[_size]{0};
            head = -1, tail = -1;
        }
        void enqueue(int num)
        {
            if(head == -1 ){
                head = 0;
                tail++;
                arr[tail] =  num ;
            }
            else if(tail < _size - 1)
            {
                tail++;
                arr[tail] =  num ;
            }
            else
            {
                cout<<"Out of range" ;
            }
        }// END ENQUEUE
        int dequeue(){
            /*if(head < tail ){
               int return_num = arr[head] ;
                cout<< "deleted num: " << arr[head] <<endl;
                head++;

                return return_num ;
            }
            else if(head == tail){
                int return_num = arr[head] ;
                head=tail=-1;
                return return_num ;

            }else{
                cout << "out of range" ;
            }*/

            if (tail != -1){
                int deleted_value = arr[0];
                cout<< "deleted num: " << deleted_value <<endl;
                for(int i =0 ; i < tail ; i++){
                    arr[i]=arr[i+1];
                }

                tail--;
                return deleted_value ;


            }
            else cout << "Empty" << endl;
        }
        void display_queue(){

            for(int i = 0 ; i <= tail ; i++ ){
                cout<< arr[i]<<endl;
            }
        }
    }; // END QUEUE CLASS

int main()
{
    Queue q(10) ;
q.dequeue();
q.enqueue(5);
q.enqueue(7);
q.enqueue(10);
q.dequeue();
q.dequeue();
q.enqueue(11);
q.dequeue() ;
q.dequeue() ;
q.dequeue(); //Empty
    return 0;
}
