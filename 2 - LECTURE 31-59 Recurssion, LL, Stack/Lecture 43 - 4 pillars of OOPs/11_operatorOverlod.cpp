#include<iostream>
using namespace std;
class A {
    public:
int a;
int b;

       void operator+ (A &obj){
        int value1 = this->a;
        int value2 = obj.a;
        cout<<"output "<<value2-value1;
       }
};

int main (){
A obj1,obj2;
obj1.a = 4;
obj1.a = 7;
obj1+obj2;
}


//syntax of op overloading -
// returntype operator + () 
// ex .  a+ b   here a will be object and b will be its parameter