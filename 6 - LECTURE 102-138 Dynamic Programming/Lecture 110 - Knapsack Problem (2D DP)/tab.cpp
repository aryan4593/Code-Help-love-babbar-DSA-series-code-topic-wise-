#include <bits/stdc++.h>
using namespace std;
int tab(vector<int> weight, vector<int> value, int capacity, int n) {
  vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

  // initialize base case
  for (int w = weight[0]; w <= capacity; w++) {
      dp[0][w] = value[0];
  }

  for (int index = 1; index < n; index++) {
	
    for (int w = 0; w <= capacity; w++) {

      int include = 0;
      if (weight[index] <= w)
        include = value[index] +
                  dp[index - 1] [w - weight[index]];

      // exclude
      int exclude = dp[index - 1][ w];
	  
  		dp[index][w] = max(exclude, include);
    }
  }
  return dp[n-1][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	return tab(weight,value, maxWeight, n);
}	