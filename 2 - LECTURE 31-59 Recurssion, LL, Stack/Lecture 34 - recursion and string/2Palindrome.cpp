#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str, int s, int e)
{
    if (s > e)
        return true;
    if (str[s] != str[e])
        return false;

    else
    {

        isPalindrome(str, s+1, e-1);
    }
}
int main()
{
    string s = "BBOOfBB";
    bool is= isPalindrome(s, 0, s.length() - 1);
    cout<<is;
    return 0;
}