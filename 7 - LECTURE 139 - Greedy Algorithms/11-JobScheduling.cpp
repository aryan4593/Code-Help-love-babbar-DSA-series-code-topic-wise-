#include <bits/stdc++.h>
using namespace std;

class info {
public:
    int id;
    int deadline;
    int profit;

    info(int id, int ded, int prof) {
        this->id = id;
        this->deadline = ded;
        this->profit = prof;
    }
};

class Solution {
    
    static bool cmp(const info &a, const info &b) {
        if (a.profit == b.profit) {
            return a.deadline > b.deadline;
        }
        return a.profit > b.profit;
    }

public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
        vector<info> vec;
        
        for (int i = 0; i < id.size(); i++) {
            vec.emplace_back(id[i], deadline[i], profit[i]);
        }
        
        sort(vec.begin(), vec.end(), cmp);
        
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        
        vector<int> schedule(maxDeadline + 1, -1);
        
        int maxProfit = 0, jobDone = 0;
        
        for (int i = 0; i < vec.size(); i++) {
            int currProfit = vec[i].profit;
            int currId = vec[i].id;
            int currDed = vec[i].deadline;
            
            
            for (int k = currDed; k > 0; k--) { 
                if (schedule[k] == -1) {  
                    schedule[k] = currId;
                    maxProfit += currProfit;
                    jobDone++;
                    break;
                }
            }
        }
        
        return {jobDone, maxProfit};
    }
};
int main(){}