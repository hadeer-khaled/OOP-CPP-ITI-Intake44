#include <iostream>

using namespace std;
void swap(int &x , int &y);
int main(){
    int x = 10 , y = 50 ;

    swap(x , y);
    cout<< "x= " << x << " y= " << y ;

return 0;
}

void swap(int &x , int &y){
    int temp = x ;
    x = y ;
    y = temp;
}
