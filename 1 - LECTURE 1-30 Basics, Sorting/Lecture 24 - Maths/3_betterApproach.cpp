#include<iostream>
#include<vector>
using namespace std;
int countPrimes(int n)
{
int count =0;
vector<bool> prime(n+1,true); // marking all as true

prime[0]=prime[1]=false;

for (int i = 2; i < n; i++)
{
    if (prime[i])
        count++;
        for (int j=2*i; j < n; j+=i)
        {
            prime[j]=0;
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