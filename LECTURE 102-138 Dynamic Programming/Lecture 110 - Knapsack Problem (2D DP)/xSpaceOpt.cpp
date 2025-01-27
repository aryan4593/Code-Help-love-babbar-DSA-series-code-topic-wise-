#include <bits/stdc++.h>
using namespace std;

int space(vector<int> weight, vector<int> value, int capacity, int n) {
vector<int> prev(capacity+1 ,0);
vector<int> curr(capacity+1 ,0);
  // initialize base case
  for (int w = weight[0]; w <= capacity; w++) {
    if (weight[0] <= capacity)
      prev[w] = value[0];

    else
      prev[w] = 0;
  }

  for (int index = 1; index < n; index++) {

    for (int w = 0; w <= capacity; w++) {

      int include = 0;
      if (weight[index] <= w)
        include = value[index] +
                  prev [w - weight[index]];

      // exclude
      int exclude = prev[ w];
	  
  		curr[w] = max(exclude, include);
    }
	prev = curr;
  }
  return prev[capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	return space(weight,value, maxWeight, n);
}	