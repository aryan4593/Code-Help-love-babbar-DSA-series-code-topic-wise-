/*
it means wrapping up data members and functioins
ex. class is capsule
fully encapsulated class - all members are private
advantage - information/data hiding
            if we want we can make class read only
            code reusability
            it helps in unit testing
*/
#include<iostream>
#include<string>
using namespace std;

//encapsulation example
class student {
    private:
        string name;
        int age;
        int height;

    public:
        int getAge(){
            return this->age;
        }
};
int main (){
    student first;
    
    return 0;
}