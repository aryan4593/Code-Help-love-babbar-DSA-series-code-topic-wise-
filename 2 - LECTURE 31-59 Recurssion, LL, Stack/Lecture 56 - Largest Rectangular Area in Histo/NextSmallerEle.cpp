#include <iostream>
using namespace std;
#include <vector>
#include <stack>

vector<int> finalPrices(vector<int> &prices){
    vector<int> ans(prices.size());
    stack<int> s;
    s.push(-1);

    int i = prices.size() - 1;

    while (i >= 0){
        int curr = prices[i];
        while (s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);

        i--;
    }
    return ans;
}

int main(){

    vector<int> vec ={8,4,6,2,3};
    vector<int> ans = finalPrices(vec);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" "<<endl;
    }
    

}