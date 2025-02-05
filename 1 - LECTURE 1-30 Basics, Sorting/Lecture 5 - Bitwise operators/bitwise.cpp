#include<iostream>
using namespace std;

int main (){

    int a=4, b=5;
    cout<<"a&b is "<< (a & b) << endl;
    cout<<"a|b is "<< (a | b) << endl;
    cout<<"~a is "<< (~a) << endl;
    cout<<"a^b is "<< (a ^ b) << endl;



    // left shift  << 
    //after left shifting a big no. we get negative  
    //in most cases (small no.) is multiplied by 2 after left shift

    //right sift  >> 
    //in most cases (small no.) is divided by 2 after right shift
    


    //when shifting a positive number padding is always with 0
    // for -ve, padding is compiler dependant 

    cout<<(17>>1)<<endl;
    cout<<(17>>2)<<endl;
    cout<<(19<<1)<<endl;
    cout<<(21<<2)<<endl;

}
