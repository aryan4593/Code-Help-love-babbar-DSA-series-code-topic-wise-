#include<iostream>
#include<string>
using namespace std;

class Animal {
    public:
        int age;
        int weight;

    public:
        void bark(){
            cout<<"barking..\n";
        }
};

class human {
    public:
    string color;
    void spwak(){
        cout<<"speaking"<<endl;
    }
};

class both : public Animal,public human{

};


int main (){
both obj1;
obj1.spwak();
obj1.bark();
}