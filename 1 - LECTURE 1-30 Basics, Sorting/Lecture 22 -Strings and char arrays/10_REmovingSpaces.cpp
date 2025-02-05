#include<iostream>
#include<string>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

int getSpaces(const string &str) {
    int count = 0;
    for (char ch : str) {
        if (ch == ' ') {
            count++;
        }
    }
    return count;
}

string replaceSpaces(string &str) {
    int spaces = getSpaces(str);
    int oldLength = str.length();
    int newLength = oldLength + (2 * spaces);

    str.resize(newLength);

    for (int i = oldLength - 1, j = newLength - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '4';
            str[j--] = '@';
        } else {
            str[j--] = str[i];
        }
    }

    return str;
}



int main (){

}