/*
we can get some properties of a class to other class this is called inheritance
ex. human --> ht,wt,age
    we craete 2 classes of men , female and inherit it with human

        human           <-- parent class/super class
    ....     ....
    ^           ^
  male          female      <--- sub class/child class
*/

#include<iostream>
using namespace std;

class Human {
    private:
        int pvt;
    public:
    int height;
    int weight;
    int age;

    int getAge (){
        return this->age;
    }
    void setage(int age){
        this->age=age;
    }
};

class Male: public Human{       //public mode of inheritance
    public:
    string color="racist";
    void sleep(){
        cout<<"male is sleeping\n";
    }
};

int main (){
    Male man1;
    cout<<man1.age<<endl;
    cout<<man1.height<<endl;
    cout<<man1.weight<<endl;
    cout<<man1.color<<endl;
    man1.sleep();
    man1.setage(5);
    cout<<man1.age<<endl;

    // man1.pvt  inaccessible as we have inherited it publicallly
    return 0;
}