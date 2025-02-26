#include <iostream>
#include <string>
using namespace std;

bool checkEqual(int a[26], int b[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}

bool checkInclusion(string s1, string s2)
{
    int count1[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }
    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};
    while (i < windowSize)
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    if (checkEqual(count1, count2))
    {
        return true;
    }

    while (i < s2.length())
    {
        char newchar = s2[i];
        int index = newchar - 'a';
        count2[index]++;

        char oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--;
        i++;
        if (checkEqual(count1, count2))
        {
            return true;
        }
    }


}
int main()
{
    string s1="ab",s2="radbshklba";

    cout<<checkInclusion(s1,s2);
}