#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i =0;
        int partLen = part.length();

        while (true) {
            int pos = s.find(part);         // when find does not founds any charrecter it throws large value of string::npos
            if (pos == string::npos) {
                break; // Exit the loop if no more occurrences are found
            }
            s.erase(pos, partLen);
        }

        return s;
        

    }
};

int main (){
    Solution s;
    string s1= "abcxyzabcxyz";
    string s2 = "xy";

    cout<<s.removeOccurrences(s1,s2);
    return 0;
}