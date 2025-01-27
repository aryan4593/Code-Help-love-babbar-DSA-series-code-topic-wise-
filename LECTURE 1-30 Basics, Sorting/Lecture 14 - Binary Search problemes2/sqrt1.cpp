#include <iostream>
using namespace std;

int sqrt(int n)
{
    int s = 0, e = n;
    int ans;
    while (s <= e)
    {
        int mid = e - (e - s) / 2;

        if (mid * mid == n)
            return mid;

        else if (mid * mid > n)
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}

double morePrecised(int n, int prec)
{
    double tempsol = sqrt(n);
    double ans;

    double fact = 1.0;
    for (int i = 0; i < prec; i++)
    {
        fact = fact / 10;
        while ((tempsol + fact) * (tempsol + fact) <= n)
        {
            tempsol = tempsol + fact;
            ans = tempsol;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "enter your number:";
    cin >> n;
    cout << "square root of " << n << " is: " << morePrecised(n, 3);
    // cout<<"hello";
}