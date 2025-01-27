#include<iostream>
using namespace std;

class Animal {
    public:
        int age;
        int weight;

    public:
        void speeak(){
            cout<<"speaking..\n";
        }
};

class dawg: public Animal {

};
class GermanShepard: public dawg{

};
int main (){
    GermanShepard g;
    g.speeak();
}