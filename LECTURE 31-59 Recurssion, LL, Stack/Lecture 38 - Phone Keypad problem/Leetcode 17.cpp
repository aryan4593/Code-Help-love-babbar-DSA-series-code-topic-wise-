#include<iostream>
#include<vector>
#include<string>
using namespace std;

    void solve (string digit, vector<string>&ans,int index,string output,string *mapping){
        if (index>=digit.length()){
            ans.push_back(output);
            return;
        }

        int number = digit[index]-'0';
        string value = mapping[number];

        for (int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solve(digit,ans,index+1,output,mapping);
            output.pop_back();//this will remove value[i] and this is called backtracking
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;
        string mapping[10] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        
        if(digits.length()==0){
            return ans;
        }

        solve (digits,ans,index,output,mapping);
        return ans;
    }

int main (){

}