//also cld as dynamic poly  this is possible through inheritance olny
#include<iostream>
using namespace std;

class Animal {
    public:
    void speak(){
        cout<<"speaking"<<endl;
    }
};

class dog: public Animal {
    public:
    void speak(){
        cout<<"Barking..."<<endl;
    }
};

int main (){
    dog D;
    D.speak();
}