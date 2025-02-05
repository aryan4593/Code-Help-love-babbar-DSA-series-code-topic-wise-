#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

    string  convert (int n){
        string str;
        // num =n;

        // 178
         while(n/10>0) {
            str.push_back(n%10+'0');
            n=n/10;

         }
              if (n<10){
            str.push_back(n+'0');
        }
        reverse(str.begin(), str.end());
        return str;
    } 


int main() {
    string str = convert(56);
    cout << str;
    return 0;
}
