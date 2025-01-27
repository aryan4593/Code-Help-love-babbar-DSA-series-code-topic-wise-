#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &boards, int k, int mid)
{
    int wallSum = 0;
    int worker = 1;
    int size = boards.size();

    for (int i = 0; i < size; i++)
    {
        if (boards[i] > mid)
        {
            return false;
        }
        if (wallSum + boards[i]<= mid)
        {
            wallSum += boards[i];
        }
        else
        {
            worker++;
            if (worker > k)
            {
                return false;
            }
            wallSum = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
    int sum = 0;
    int size = boards.size();
    for (int i = 0; i < size; i++)
    {
        sum = sum+ boards[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e - s) / 2;
    cout<<"mid is "<<mid<<endl;
    while (s <= e)
    {
        if (isPossible(boards, k, mid) == 1)
        {
            cout<<"cond for "<<mid <<"is satissfied"<<endl;
            ans = mid;
            e = mid - 1;
            cout <<"answer is " <<ans << endl;
        }
        else
        {
            s = mid + 1;
            cout<<"start is now "<<s<<endl;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<int> v = {10, 20, 30, 40};
    cout << findLargestMinDistance(v, 2);
}