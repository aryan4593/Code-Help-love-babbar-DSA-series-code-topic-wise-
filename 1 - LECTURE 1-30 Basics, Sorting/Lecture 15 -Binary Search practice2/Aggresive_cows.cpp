#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int  mid) {
    int cowCount = 1;
    int lasPos = stalls[0];

    for (int i = 0;i<stalls.size();i++) {
        if (stalls[i]-lasPos >= mid ){
            cowCount++;
            if( cowCount == k){
                return true;
            }
            lasPos = stalls[i];

        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
int s =0;
int ans =-1;

        sort (stalls.begin(),stalls.end());

    int maxi =-1;
    for (int i =0;i<stalls.size();i++){
        maxi = max ( maxi, stalls[i]);
    }
        int e = maxi;
        int mid = s +(e-s)/2;
    int ans = -1;
        while(s<=e){
            if (isPossible(stalls, k,mid)){
                ans = mid;
                s = mid +1;
            }
            else {
                e = mid-1;
            }
            mid = s +(e-s)/2;
        }
   return ans;  }

   int main (){
    vector<int> v1;
    v1 = {};
   }