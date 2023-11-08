#include <iostream>

using namespace std;

class complex_{
    int real ;
    int img ;

    public:
        int getReal(){
            return real;
        };
        void setReal(int real_){
            real = real_;
        };
        int getImg(){
            return img;
        };
        void setImg(int img_){
            img = img_;
        };

        // -------------------- Method 1 -----------------------
        void printIn(){
            cout<<"Print with In class definition:  ";
            cout << real;
            if(img > 0){
                cout << " + " << img << "j" << endl;
            }
            else if(img > 0){
                cout <<  img << "j"<<endl;
            }
            else{}
        }
        complex_ addIn(complex_ comp ){
            complex_ result ;
            result.real = real + comp.real ;
            result.img = img + comp.img ;

            return result ;
        }

        complex_ subIn(complex_ comp ){
            complex_ result ;
            result.real = real - comp.real ;
            result.img = img - comp.img ;

            return result ;
        }

        // -------------------- Method 2 -----------------------

        void printOut() ;
        complex_ addOut(complex_ comp );
        complex_ subOut(complex_ comp ) ;


        friend complex_ subFriend( complex_ complexNum1 , complex_ complexNum2 );
};

      complex_ subFriend( complex_ complexNum1 , complex_ complexNum2 ){
            complex_ result ;
            result.real = complexNum1.real - complexNum2.real ;
            result.img = complexNum1.img - complexNum2.img ;

            return result ;
        }

    void complex_::printOut(){
        cout<<"Print with out class definition:  " ;
        cout << real;
        if(img > 0){
            cout << " + " << img << "j" <<endl ;
        }
        else if(img > 0){
            cout <<  img << "j"  <<endl ;
        }
        else{}
    };

     complex_ complex_::addOut(complex_ comp ){
            complex_ result ;
            result.real = real + comp.real ;
            result.img = img + comp.img ;

            return result ;
        }

    complex_ complex_::subOut(complex_ comp ){
            complex_ result ;
            result.real = real - comp.real ;
            result.img = img - comp.img ;

            return result ;
        }

void printStandAlone(complex_ complexNum );
complex_ addStandAlone( complex_ complexNum1 , complex_ complexNum2 );
complex_ subStandAlone( complex_ complexNum1 , complex_ complexNum2 ) ;
//complex_ subFriend( complex_ complexNum1 , complex_ complexNum2 )

int main()
{
    complex_ complexNum_1 ;
    complex_ complexNum_2 ;

    complex_ complexNum_3 ;
    complex_ complexNum_4 ;
    complex_ complexNum_5 ;
    complex_ complexNum_6;

    complexNum_1.setReal(5);
    complexNum_1.setImg(7);

    complexNum_2.setReal(10);
    complexNum_2.setImg(10);

    //-------------------- Add Functions --------------------
    complexNum_3 = complexNum_2.addIn(complexNum_1);
    complexNum_4 = complexNum_2.addOut(complexNum_1);
    complexNum_5 = addStandAlone(complexNum_2, complexNum_1);


    //-------------------- sub Functions --------------------
    complexNum_3 = complexNum_2.subIn(complexNum_1);
    complexNum_4 = complexNum_2.subOut(complexNum_1);
    complexNum_5 = subStandAlone(complexNum_2, complexNum_1);
    complexNum_6 = subFriend(complexNum_2, complexNum_1);


    //-------------------- Print Functions --------------------
    complexNum_3.printIn();
    complexNum_4.printOut();
    printStandAlone(complexNum_5);

    return 0;
}

// -------------------- Method 3: StandAlone -----------------------
void printStandAlone(complex_ complexNum ){
    cout<<"Print with  StandAlone:  ";
        cout << complexNum.getReal();
        if(complexNum.getImg() > 0){
            cout << " + " << complexNum.getImg() << "j"  <<endl ;
        }
        else if(complexNum.getImg() > 0){
            cout <<  complexNum.getImg()<< "j"  <<endl ;
        }
        else{}
}

complex_ addStandAlone( complex_ complexNum1 , complex_ complexNum2 ){
            complex_ result ;
            result.setReal( complexNum1.getReal() +complexNum2.getReal() ) ;
            result.setImg (complexNum1.getImg() +complexNum2.getImg() );

            return result ;
}

complex_ subStandAlone( complex_ complexNum1 , complex_ complexNum2 ){
            complex_ result ;
            result.setReal( complexNum1.getReal()-complexNum2.getReal() ) ;
            result.setImg (complexNum1.getImg()-complexNum2.getImg() );

            return result ;
}

 // ------------------ Friend Function-------------------



