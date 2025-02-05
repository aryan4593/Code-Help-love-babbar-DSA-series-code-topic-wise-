#include <iostream>
using namespace std;

void update(int n)
{
    n++;
}

void update2(int &n) //reference variable           ///this is called as pass by reference
{
    n++;
}

int & func(int a){       //return by reference   //not corrext as all memory get deleted after function call is done as all are ocal variable , what are we returning???
    int num =a ;
    int &ans = num;
    return ans;
}

//similar for pointer ex-

int * fun (int n){
    int *ptr = &n;
    return ptr;         //this is wrong too, as pointer is created locally
}
int main()
{
    int n = 5;
    cout << "Before " << n << endl;
    update(n);
    cout << "update 1..." << endl;
    cout << "after " << n << endl;

    cout << "Before " << n << endl;
    update2(n);
    cout << "update 2..." << endl;
    cout << "after " << n << endl;

    // func(n);
    return 0;
}

//