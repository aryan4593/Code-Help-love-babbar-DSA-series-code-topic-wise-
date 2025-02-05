//class is user defined datatype
//object is instance of class

#include<iostream>
#include "Hero.cpp"  //this is how you import class from other folder
using namespace std;

class Hero {
    char name [100];

    public:
    int health;
    char level;
};

class empty {

};

int main (){
    Hero h1;
    cout<<"size: "<<sizeof(h1);
    empty e;
    cout<<"size: "<<sizeof(e);  //empty class gets one byte of memory

    
h1.health= 99;

    return 0;
}