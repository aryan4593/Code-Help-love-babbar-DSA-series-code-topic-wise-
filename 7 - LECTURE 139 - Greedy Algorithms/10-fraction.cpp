#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Item {
public:
    int val, wt;
    
    Item(int val, int wt) {
        this->val = val;
        this->wt = wt;
    }
};

class Solution {
public:
    static bool cmp(pair<double, Item> &a, pair<double, Item> &b) {
        return a.first > b.first;
    }

    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity) {
        vector<pair<double, Item>> v;

        for (int i = 0; i < wt.size(); i++) {
            double perVal = (1.0 * val[i]) / (1.0 * wt[i]);
            v.push_back({perVal, Item(val[i], wt[i])});
        }

        sort(v.begin(), v.end(), cmp);

        double totalVal = 0.0;

        for (int i = 0; i < wt.size(); i++) {
            if (capacity == 0) break;

            if (v[i].second.wt <= capacity) {
                // Take the full item
                totalVal += v[i].second.val;
                capacity -= v[i].second.wt;
            } else {
                // Take the fractional part
                totalVal += capacity * v[i].first;
                capacity = 0;
            }
        }

        return totalVal;
    }
};
