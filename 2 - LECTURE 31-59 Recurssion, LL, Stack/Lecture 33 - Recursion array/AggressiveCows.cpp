#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible (vector<int> stalls,int num,int cows){
    int cowCount =1;
    int initialStall = stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i]-initialStall >= num){
            cowCount++;
            initialStall = stalls[i];
        }
        if (cowCount==cows)
            return true;

        
    }
    return false;
}
int solveRecursive(const vector<int> &stalls, int s, int e, int k) {
    if (s > e) {
        return e;
    }

    int mid = s + (e - s) / 2;

    if (isPossible(stalls, mid, k)) {
        return solveRecursive(stalls, mid + 1, e, k);
    } else {
        return solveRecursive(stalls, s, mid - 1, k);
    }
}
int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(), stalls.end());
    int s = 1;
    int e = stalls[n - 1] - stalls[0];
    return solveRecursive(stalls, s, e, k);
}
        
int main (){


}