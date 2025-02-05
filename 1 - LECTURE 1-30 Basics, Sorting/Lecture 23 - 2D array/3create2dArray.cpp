#include <iostream>
using namespace std;
bool isPresent(int arr[][3],int target,int row, int col){
        for (int i =0;i<row;i++){
            for (int j = 0; j < col; j++)
            {
                if (arr[i][j]== target)
                return 1;
            }
            
        }
        return 0;
}
int main()
{
    int arr[3][4]; // arr[row][col]
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            // cin >> arr[i][j];
        }
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {

    //         cout << arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // int array [3][3]={1,2,3,4,5,6,7,8,9};
    //     for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {

    //         cout << array[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int array [3][3]={{1,2,3},{4,5,6},{7,8,9}}; // row wise
        for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            cout << array[i][j]<<" ";
        }
        cout<<endl;
    }


    cout<<"enter the element to search "<<endl;
    int target;
    cin>>target;
    if (isPresent(array,target,3,3)){
        cout<<"found\n";
    }
    else cout<<"not found "<<endl;
    return 0;
}