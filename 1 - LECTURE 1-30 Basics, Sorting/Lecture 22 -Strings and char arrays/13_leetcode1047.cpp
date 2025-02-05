#include<iostream>
#include<string>
class Solution {
public:
    string removeDuplicates(string s) {
        string temp =s;
        for(int i =0;i<( temp.length()-1);i++){
    abccba        if (temp[i]==temp[i+1]){
                temp.erase(i,2);
                if(temp.empty()){
                    temp="";
                    break;
                }
                i=-1;
            }
        }
        return temp;
    }
};

int main (){
    string s= "vjdfhhfukhgfffdii";
    
   cout<< removeDuplicates(s);
     return 0;
}