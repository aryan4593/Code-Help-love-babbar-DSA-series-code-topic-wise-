#include<bits/stdc++.h>
using namespace std;

#define P pair<int,int>

class Solution {
    vector<P> directions = {{1,0} , {-1,0} ,{0,1} , {0,-1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans = 0;
        int m = heights.size() , n = heights[0].size();
        vector<vector<int>> distance (m , vector<int> (n , INT_MAX));

        priority_queue<pair<int  , P> , vector<pair<int , P>>, greater<pair<int , P>>  > pq; //dist , i , j minheapq

        pq.push({heights[0][0] , {0 ,0}});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int dist = top.first;
            P node = top.second;
            int i = node.first;
            int j = node.second;

            for(auto&dir : directions){
                int x = i + dir.first;
                int y = j + dir.second;

                if(x < 0 || x >= m || y < 0 || y>=n) continue; // invalid index;

                if(dist + heights[x][y] < distance[x][y]){
                    cout<<"updated distance["<<x<<"]["<<y<<"] as "<<heights[x][y] + dist <<endl;
                    distance[x][y] =  heights[x][y] + dist;
                    pq.push({distance[x][y], {x , y}});
                }
            } 
            
        }

        return distance[m-1][n-1];
    }
};


int main(){
    vector<vector<int>> vec = {{1,2,2},{3,8,2},{5,3,5}};
    Solution s1;
    s1.minimumEffortPath(vec);
    return 0;
}
/**
   1 2 2
   3 8 2
   5 3 5
 */