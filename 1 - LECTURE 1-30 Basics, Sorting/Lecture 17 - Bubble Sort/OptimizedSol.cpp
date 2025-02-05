#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n ; i ++)
    {
        //for round 1 to n-1

        bool swapped = false;

        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {

                swap(arr[j], arr[j + 1]);
                swapped= true;
            }
        }

        if (swapped == false) break;
    }
}



int  main (){
    vector <int>v1 = {6 ,2, 8, 4, 10};

    bubbleSort(v1,v1.size());

    for (int i =0;i<v1.size();i++){
        cout<<v1[i]<<endl;
    }
}
