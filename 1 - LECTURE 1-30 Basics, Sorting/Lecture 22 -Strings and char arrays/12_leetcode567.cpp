#include<iostream>
#include<string>

using namespace std;

int asciSum(string str) {
    long long int sum = 1;
    for (int i = 0; i < str.length(); i++) {
        sum = sum * str[i];
    }
    cout << "required sum is " << sum;
    return sum;
}

bool checkInclusion(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    int sum = asciSum(s2); // calculate the ASCII product sum of s2
    long long int target = 1;
    bool ans = false;

    int ptr1 = 0, ptr2 = len2 - 1;

    while (ptr2 < s1.length()) {
        for (int i = ptr1; i < ptr2 + 1; i++) {
            target *= s1[i];
        }
        cout << endl << "target for index " << ptr1 << " is " << target << endl;
        if (target == sum) {
            ans = true;
            cout << "entered in if\n";
        }
        target = 1;
        ptr1++; ptr2++;
    }

    return ans;
}

int main() {
    string s1 = "islander";
    string s2 = "islander";

    cout << checkInclusion(s1, s2);
}
