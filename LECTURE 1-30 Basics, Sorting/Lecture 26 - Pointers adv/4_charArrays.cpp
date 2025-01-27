#include<iostream>
using namespace std;

int main (){
    int arr[5]={1,2,3,4,5};
    char ch[6]="abcde";

    cout<<arr<<endl;        // address of first memory
    cout<<ch<<endl;         //will print entire content

    char *c =&ch[0];
    cout<<c<<endl;      //this too will print entire element

    // Printing won't stop until ptr gets a null charecter

    cout<<endl<<endl;
// IMP - what if there is no null char in string
    char temp ='j';
    char *p = &temp;
    cout<<p<<endl;
    return 0;
}