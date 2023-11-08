#include <iostream>
using namespace std ;

void swap( int* x,int* y) ;
int main(){
    int x = 50 ;
    int y = 10;
    
    cout << " ######### Before Swapping #########  "<< endl;
    cout << " The value of x: " << x  << " The value of y: " << y << endl ;
    
    swap(&x , &y ) ;
    
    cout << " ######### After Swapping #########  "<< endl;
    cout << " The value of x: " << x  << " The value of y: " << y ;
    return 0 ;
}
void swap( int* x,int* y) {
    *x = *x + *y ;
    *y = *x - *y ;
    *x = *x - *y;
}
