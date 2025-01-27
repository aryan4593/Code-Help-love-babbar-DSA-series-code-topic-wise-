#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve (string str,vector<string> &ans,int index){
    if (index>=str.length()){
        ans.push_back(str);
        return;
    }

    
    for(int i =index;i<str.length();i++){
        swap(str[index],str[i]);
        solve(str,ans,index+1);
        swap(str[index],str[i]);

    }


    


}
vector<string> generatePermutations(string &str)
{
    vector<string> ans;
    string output;
    int index =0;

     solve (str,ans,index);
     
     
     return ans;
}

int main(){

    string str = "abc";
    vector<string> v = generatePermutations(str);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    
}