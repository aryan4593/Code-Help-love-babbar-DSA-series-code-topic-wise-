#include <iostream>
using namespace std;

void update (int **p2){
    // p2 =p2+1;  this won't change anything as p(which contain value of add of ptr1) is like value for this function

    // *p2 = *p2+1; // *p2 means value present at p2 which is addr of ptr1, thats why it becomes call by reference and ptr1 get chaanges
    **p2 = **p2+1; //this will change value of i
}
int main()
{
    int i = 5;
    int *ptr = &i;
    int **ptr2 = &ptr;

    cout << "printing ptr " << ptr << endl;
    cout << "address of ptr " << &ptr << endl;

    cout << "printing *ptr2 " << *ptr2 << endl;   //*ptr2 means value present ar ptr1

    //ways of printing i
    cout<<"1st way i="<<i<<endl;
    cout<<"3rd way i="<<*ptr<<endl;
    cout<<"2nd way i="<<**ptr2<<endl;

    //ways of printing address of i
    cout<<"address of i "<<endl;
    cout<<"1st way &i="<<&i<<endl;
    cout<<"3rd way &i="<<ptr<<endl;
    cout<<"2nd way &i="<<*ptr2<<endl;

    cout<<"before i "<<i<<endl;
    cout<<"before ptr "<<ptr<<endl;
    cout<<"before ptr2 "<<ptr2<<endl;
    update(ptr2);
    cout<<"after i "<<i<<endl;
    cout<<"after ptr "<<ptr<<endl;
    cout<<"after ptr2 "<<ptr2<<endl;
    return 0;
}