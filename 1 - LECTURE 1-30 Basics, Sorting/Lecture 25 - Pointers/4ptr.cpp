#include<iostream>
using namespace std;

int main (){
    //    int num =5;
    // int *p =&num;
    // int *q = p;

    // cout<<p<<"-"<<q<<endl;
    // cout<<*p<<"-"<<*q;          //copying pointer

    int i =3;
    int *t =&i;
    *t = *t +1;
    cout<<"\nt is "<<*t<<endl;
cout<<"t before "<<t<<endl<<"t after ";
    // let address of i is 100 so t is 100
    t =t+1;
    
    //this will increment by 4 byte as integer takek 4 bytes therefore t = 104
    //in short it will point one integer ahead's memory
    cout<<t;
       return 0; 
}

       
