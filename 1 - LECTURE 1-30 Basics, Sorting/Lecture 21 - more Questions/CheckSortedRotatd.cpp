#include <iostream>
#include <vector>
using namespace std;
int maxInd(vector<int> v)
{
    int n = v.size();
    int max = v[0];
    int maxInd;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= max)
        {
            max = v[i];
            maxInd = i;
        }
        
    }
    cout<<"max ind is "<<maxInd<<endl;
    return maxInd;
}
bool check(vector<int> &nums)
{
    int n = nums.size();
    int ind = maxInd(nums);
    bool sort1 = true, sort2 = true;
int j;
    for (int i = 0; i <= ind; i++)
    {
        for (j=i+1; j <= ind; j++)
        {
            
            if (nums[i] > nums[j])
            {
                sort1 = false;
                // cout << "setting sort1 as false \n";
                exit;
            }
        }
    }
    // cout << "sort1 is " << sort1 << endl;
    j = ind + 2;
    // cout<<"J IS "<<j<<endl;
    for (int i = ind + 1; i < n; i++)
    {
        // cout<<"entered in for 1"<<endl;

        for (j=i+1; j < n; j++)
        {
            // cout<<"entered in 2nd for loop\n";
            // cout<<"i is "<<i<<" and  j is "<<j<<endl;
            if (nums[i] > nums[j])
            {
                // cout << "setting sort2 as false \n";
                sort2 = false;
            }
        }
    }

    // cout << "sort2 is " << sort2 << endl;

    if (sort1 == true && sort2 == true)
    {
        return true;
    }
    else
        return false;
}

int main()
{

    vector<int> v = {1,4,1,2,3,5};
    cout << check(v);
}