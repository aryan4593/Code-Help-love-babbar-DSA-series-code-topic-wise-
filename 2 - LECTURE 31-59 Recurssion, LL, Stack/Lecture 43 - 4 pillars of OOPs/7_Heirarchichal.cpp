#include<iostream>
#include<string>
using namespace std;

class A {
    public:
       void func1(){
        cout<<"inside function 1"<<endl;
       }
};

class b: public A {
    public:
        void func2(){
        cout<<"inside function 2"<<endl;
       }
};
class C: public A {
    public:
        void func3(){
        cout<<"inside function 3"<<endl;
       }
};



int main (){
A obj1;
obj1.func1();
b obj2;
obj2.func1();
obj2.func2();

C obj3;
obj3.func1();
obj3.func3();
}