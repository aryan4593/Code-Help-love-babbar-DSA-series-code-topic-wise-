#include<iostream>
using namespace std;
int i =5; //global variable
void share (){
    i =3;   // it will get updated
    cout<<i<<endl;
}


int main (){
    cout<<i<<endl;
    share();
    cout<<i;
    return 0;
}

//using global variable is a bad practice; as anuone can change this
//alternate way - use reference varibale