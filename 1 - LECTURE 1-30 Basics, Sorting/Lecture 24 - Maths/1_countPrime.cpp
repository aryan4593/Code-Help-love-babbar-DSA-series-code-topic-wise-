#include <iostream>
using namespace std;
bool isPrime(int n){

    if (n<=1){
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n%i==0){
            return false;
        }
    }

    return true;
    
}
int countPrimes(int n)
{
   
    int count =0;
    for (int i = 1; i < n; i++)
    {
        if (isPrime(i)){
            count++;
        }

    }
    return count;
    
}
int main()
{
    cout<<"enter n ";
    int n; cin>>n;

    cout<<countPrimes(n);
}