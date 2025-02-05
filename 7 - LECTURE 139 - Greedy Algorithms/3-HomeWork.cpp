#include<bits/stdc++.h>
using namespace std;
class Solution{
        #define P pair<int, pair<int,int>>
public:
    static bool cmp (P a, P b){
        return a.second.first < b.second.first;
        
    }
    vector<int> maxMeetings(int N,vector<int> &start,vector<int> &end){
        int n = start.size();
        vector<P> vec;
        
        for(int i=0;i <n ;i++){
            vec.push_back({start[i], {end[i], i}});
        }
        
        sort(vec.begin(), vec.end(), cmp);
        
        vector<int> ans;
        int endTime = vec[0].second.first;
        ans.push_back(vec[0].second.second + 1);
        for(int i=1; i<n; i++){
            // check if it can attend
            int stTime = vec[i].first;
            
            if(stTime > endTime){
                ans.push_back(vec[i].second.second + 1);
                endTime= vec[i].second.first;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main(){
    
}