#include<iostream>
using namespace std;
#include<queue>
void printQueue(deque<int> q){
        cout<<"queue is ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop_front();
    }
    cout<<endl;
}
int solve(int* arr,int n,int k){
    deque<int> maxi(k);
    deque<int> mini(k);

    //addition of first k
    int maximum=INT32_MIN;
    int minimum=INT32_MAX;
    for(int i =0;i<k;i++){
        while(!maxi.empty() && arr[maxi.back()]<=arr[i])
{            cout<<"arr[maxi.back()] "<<arr[maxi.back()]<<" <= "<<"arr[i] "<<arr[i]<<endl;
            maxi.pop_back();}
        while(!mini.empty() && arr[mini.back()]>=arr[i])
            mini.pop_back();

        maxi.push_back(i);
        printQueue(maxi);
        mini.push_back(i);
        cout<<"i is "<<i<<endl;
    }
        int ans=0;
        ans+=arr[maxi.front()]+arr[mini.front()];

    for (int i = k; i < n; i++)
    {

        //next window
        while(!maxi.empty() && i - maxi.front()>=k){
            maxi.pop_front();
        }
        while(!mini.empty()&&i - mini.front()>=k){
            mini.pop_front();
        }

        //addition
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()]>=arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
                cout<<"i is "<<i<<endl;
        printQueue(maxi);
        ans+=arr[maxi.front()]+arr[mini.front()];
    }
    return ans;
}

int main (){
    int arr[7]={2,5,-1,7,-3,-1,-2};
    cout<<"array is 2,5,-1,7,-3,-1,-2"<<endl;
    cout<<solve(arr,7,4)<<endl;
}