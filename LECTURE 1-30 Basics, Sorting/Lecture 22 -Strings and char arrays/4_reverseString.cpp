#include<iostream>
using namespace std;

int getLength (char arr[])
{
    int count =0; int i =0;
    while(arr[i]!='\0'){
        count++;
        i++;
    }

    return count;
}

void reverse (char name[],int n ){
    int s =0,e = n-1;

    while(s<e){
        swap(name[s++],name[e--]);
    }
}
int main (){
    char name[20];
    cout<<"Enter your name ";
    cin>>name;
    int n = getLength(name);
    reverse(name,n);
    cout<<"reverse string is "<<name;
    
}