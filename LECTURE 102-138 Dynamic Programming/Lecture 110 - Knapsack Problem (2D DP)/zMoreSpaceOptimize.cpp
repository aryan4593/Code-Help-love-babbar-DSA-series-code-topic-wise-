using namespace std;
#include <bits/stdc++.h>

int space(vector<int> weight, vector<int> value, int capacity, int n) {
// vector<int> curr(capacity+1 ,0);
vector<int> curr(capacity+1 ,0);
  // initialize base case
  for (int w = weight[0]; w <= capacity; w++) {
    if (weight[0] <= capacity)
      curr[w] = value[0];

    else
      curr[w] = 0;
  }

  for (int index = 1; index < n; index++) {

    for (int w = capacity; w >=0; w--) {

      int include = 0;
      if (weight[index] <= w)
        include = value[index] +
                  curr [w - weight[index]];

      // exclude
      int exclude = curr[ w];
	  
  		curr[w] = max(exclude, include);
    }
  }
  return curr[capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	return space(weight,value, maxWeight, n);
}	