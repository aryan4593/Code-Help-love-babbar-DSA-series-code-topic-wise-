#include<iostream>
#include<string>
using namespace std;

char getMax (string s){
    int arr[26]={0};
    for(int i =0;i<s.length();i++){
        char ch = s[i];
        int number = 0;
        if (ch>='a' && ch<='z' ){
            number = s[i]-'a';
        }
        else{
            number = s[i]-'a';
           
        }
         arr[number]++;
    }

    int maxi =-1,ans =0;
    for(int i =0;i<26;i++){
        if (maxi<arr[i]){
            maxi = arr[i];
            ans =i;
        }
    }


    char cha = ans +'a';
    return cha;
}
int main (){
string s;
cin>>s;
cout<<"maximum number of charecter is "<<getMax(s);
}