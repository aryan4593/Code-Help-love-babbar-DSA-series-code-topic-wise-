#include<iostream>
#include<string>
using namespace std;

class A {
    public:
       void func(){
        cout<<"inside function 1"<<endl;
       }
};

class b{
    public:
        void func(){
        cout<<"inside function 2"<<endl;
       }
};
class C: public A ,public b {
    
};



int main (){
C obj;
// obj.func(); //will give eror
obj.A::func();
obj.b::func();
}