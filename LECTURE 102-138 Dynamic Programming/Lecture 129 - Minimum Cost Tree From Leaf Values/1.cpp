#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(vector<int>&arr , map<pair<int,int>, int>&maxi , int left , int right){
        if(left == right) return 0; //leaf node
        
        int ans = INT_MAX;
        
        for(int i=left; i<right; i++){
            int temp = maxi[{left,i}] * maxi[{i+1 , right}] +
                     solve(arr, maxi ,left,i) + solve(arr,maxi ,i+1, right);
            ans = min(ans,temp);
        }
        return ans;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        // precompute
        map<pair<int,int>,int> maxi;
        for(int i=0 ;i<n ;i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1;j< n ;j++){
                 maxi[{i,j}]= max(arr[j] ,  maxi[{i,j-1}]);
            }
        }

        return solve(arr , maxi,0,n-1);
    }
};
int main(){
    
}