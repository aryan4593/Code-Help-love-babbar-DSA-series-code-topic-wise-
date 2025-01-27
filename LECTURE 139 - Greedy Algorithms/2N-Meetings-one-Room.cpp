#include<bits/stdc++.h>
using namespace std;
class Solution {
    #define P pair<int,int>
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    static bool cmp (P a, P b){
        return a.second < b.second;
        
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<P> vec;
        
        for(int i=0;i <n ;i++){
            vec.push_back({start[i], end[i]});
        }
        
        sort(vec.begin(), vec.end(), cmp);
        
        int count = 1;
        int endTime = vec[0].second;
        for(int i=1; i<n; i++){
            // check if it can attend
            int stTime = vec[i].first;
            
            if(stTime > endTime){
                count++;
                endTime= vec[i].second;
            }
        }
        
        return count;
    }
};

int main(){
    
}