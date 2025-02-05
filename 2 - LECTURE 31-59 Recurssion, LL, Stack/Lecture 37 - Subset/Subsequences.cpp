#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include <bits/stdc++.h> 

#include <bits/stdc++.h> 
void solve(string str, int index, string output, vector<string> &ans) {
    if (index >= str.length() ) {
		if ( output.length()>0){ //no need of empty string
	    ans.push_back(output);
		}
        return;		

    }

    // Exclude the current character and move to the next character
    solve(str, index + 1, output, ans);

    // Include the current character and move to the next character
    char element = str[index];
	output.push_back(element);
    solve(str, index + 1, output, ans);
}

vector<string> subsequences(string &str){
	string output="";
	vector<string> ans;
	int index=0;
	solve (str,index,output,ans);
	return ans;
	// Write your code here
	
}

int main() {
    string str = "abc";
    string output = "";
    vector<string> ans;
    solve(str, 0, output, ans);
    
    for (const auto &s : ans) {
        cout << s << endl;
    }

    return 0;
}
