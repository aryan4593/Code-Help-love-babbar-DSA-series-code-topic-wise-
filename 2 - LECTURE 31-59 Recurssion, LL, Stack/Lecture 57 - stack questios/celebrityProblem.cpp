#include<iostream>
using namespace std;
#include<stack>
#include<vector>
   
   
   
    int celebrity(vector<vector<int> >& mat) {
    //celebrity knows no one so it's row will be 0
    //celebrity is known to everyone so his column will be 1 (except diagonal)
    
    stack<int> s;
    int people = mat.size();
    int i =0;
    while(i<people){
        s.push(i);
        i++;
    }
    
    
    while(i!=1){
    int a=s.top();
    s.pop();
    int b=s.top();
    s.pop();
    i-=2;
    
    if(mat[a][b]==1){
        s.push(b);
        i++;
    }
    else if(mat[b][a]==1){
        s.push(a);
        i++;
    }
    }
    for(int i =0;i<people;i++){
        if(i==s.top()){
            continue;
        }
        if(mat[s.top()][i]==1){
            return -1;
        }
    }
    for(int i =0;i<people;i++){
        if(i==s.top()){
            continue;
        }
        if(mat[i][s.top()]==0){
            return -1;
        }
    }
    return s.top();
        
    }

int main(){

vector<std::vector<int>> mat = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
cout<<celebrity(mat);
}