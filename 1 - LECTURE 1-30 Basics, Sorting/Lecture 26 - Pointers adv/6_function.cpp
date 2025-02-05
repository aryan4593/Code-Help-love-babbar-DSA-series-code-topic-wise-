#include <iostream>
using namespace std;

void print(int *p)
{
    cout << *p << endl;
}

void updateVal(int *p)
{
    *p = *p + 1;
}
void update(int *p)
{
    p = p + 1;
}

int getSum (int arr[], int size){  // or we can write it as  int getSum (int *arr, int size)

    cout<<"size: "<<sizeof(arr)<<endl;
    int sum =0;
    for (int i = 0; i < size; i++)
    {
        /* code */
        sum=sum+arr[i];
    }
    return sum;
    
}
int main()
{
    int value = 5;
    int *ptr = &value;
    print(ptr);    
    
    cout<<"Before "<<ptr<<endl;
    update(ptr);
    cout<<"after "<<ptr<<endl;

    cout<<"Before "<<*ptr<<endl;
    updateVal(ptr);
    cout<<"after "<<*ptr<<endl;              
              

    //Note - we can change value but can't change address as 
    // when we pass ptr, address of variable passes to function so for function it is call by ref;
    // but when we try to change address, it is just value so call by value 


    int arr[6]={1,2,3,4,5,8};
    cout<<"Sum is "<<getSum(arr,5)<<endl;
    //we got value of size 4 which is size of pointer, this is because when we pass an array instead of array a pointer is passed!!!!

    //it's advantage - we can pass part of array by it 
    // exaample

        cout<<"Sum is "<<getSum((arr+3),3)<<endl;  //as pointer is passed we can write as arr+3
    return 0;
}