#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include <bits/stdc++.h> 
bool isSafe(vector < vector < int >> & arr , vector < vector < bool >> visited,  int i , int j ){
    return  i<arr.size() && j< arr.size() 
    && i>=0 && j>=0 && arr[i][j]==1 &&visited[i][j]!=1;
}

void solve(vector < vector < int >> & arr , vector < vector < bool >> & visited, 
    int n , int i , int j , string& path,vector<string> &ans ){
        if(i==n-1 && j==n-1){
            ans.push_back(path);
            return;
        }


        //D
        if(isSafe(arr,visited,i+1,j)){
            visited[i][j]=true;
            path.push_back('D');
            solve(arr,visited, n,i+1, j, path, ans);
            visited[i][j]=false; 
            path.pop_back();

        }

        //L
        if(isSafe(arr,visited,i,j-1)){
            visited[i][j]=true;
            path.push_back('L');
            solve(arr,visited, n,i, j-1, path, ans);
            visited[i][j]=false;
            path.pop_back();

        }
        //R
        if(isSafe(arr,visited,i,j+1)){
            visited[i][j] = true;
            path.push_back('R');
            solve(arr,visited,n,i,j+1,path,ans);
            visited[i][j] = false;
            path.pop_back();
        }
        //U
        if(isSafe(arr,visited,i-1,j)){
            visited[i][j] = true;
            path.push_back('U');
            solve(arr,visited,n,i-1,j,path,ans);
            visited[i][j] = false;
            path.pop_back();
        }

    }
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<vector<bool>> visited(n,vector<bool>(n, 0));
    string path ="";
    vector<string> ans;
    if(arr[0][0]==0) return ans;
    solve(arr,visited, n , 0 ,0 ,path,ans);
    return ans;

}

//T.c = 4^n*n
//S.C =o(n*m)