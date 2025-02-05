#include <bits/stdc++.h> 
using namespace std;
int solve(vector<int>weight , vector<int> value ,int index, int capacity, vector<vector<int>> &dp){
	if(index == 0){
		if(weight[0] <= capacity) 
			return value[0];

		else 
			return 0;
	}
	
	if(dp[index][capacity] != -1) return dp[index][capacity];

	 /// include (check if possible)
	int include = 0;
	if(weight[index] <= capacity)
		include = value[index] + solve(weight , value , index-1 , capacity - weight[index] , dp); 
	
	// exclude
	int exclude = solve(weight , value, index-1 , capacity ,dp);

	dp[index][capacity] = max(exclude , include);
	return dp[index][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// 2d dp
	vector<vector<int>> dp(n , vector<int>(maxWeight +1, -1));
	return solve(weight , value , n-1 , maxWeight ,dp); //traverse fronm back 
}