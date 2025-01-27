// O(k) space

#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

#include<queue>

int getKthLargest(vector<int> &arr, int k)
{
    priority_queue <long long , vector<long long> , greater <long long> >pq;  //min heap

    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for(int j = i; j < arr.size(); j++) {
			sum+=arr[j];
            if(pq.size()< k){
				pq.push(sum);
			}
			else{
				if(pq.top() < sum){
					pq.pop();
					pq.push(sum);
				}
			}
        }
    }

    // Sort the bruteForce array to get the largest sums

    // Return the k-th largest element
    return pq.top();
}

