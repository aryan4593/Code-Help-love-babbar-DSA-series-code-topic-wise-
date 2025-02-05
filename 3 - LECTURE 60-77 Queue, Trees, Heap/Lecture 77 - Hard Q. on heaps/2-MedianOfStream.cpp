#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class MedianFinder {
public:
    int n;
    priority_queue<int> maxHeap;
    priority_queue <long long , vector<long long> , greater <long long> > minHeap;  //
    MedianFinder() {
         n=0;
    }
    
     void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
        } else if (num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps so that the size difference between them is at most 1
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        n++;
    }
    double findMedian() {
        double ans;
        if(n%2 == 0){
            ans = minHeap.top() + maxHeap.top();
            ans= ans/2.00;
        }
        else{
            ans = maxHeap.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */