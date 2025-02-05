#include <iostream>
using namespace std;

void printSum(int arr[][3], int row, int col)
{
    
    for (int i = 0; i < 3; i++)
    {
        int sum=0;
        for (int j = 0; j < 3; j++)
        {
            sum = sum+ arr[i][j];
        }
        cout<<sum<<" ";
    }
}

int LargestRow (int arr[][3],int row,int col){
    int maxi = INT_FAST16_MIN;
    int rowIndex = -1;
    for (int i = 0; i < 3; i++)
    {
        int sum=0;
        for (int j = 0; j < 3; j++)
        {
            sum = sum+ arr[i][j];
        }
        if(sum>maxi){
            maxi = sum;
            rowIndex= i;

        }
    }
    cout<<"the max sum is "<<maxi<<endl;
    cout<<"row is "<<rowIndex<<endl;

    return maxi;

}
int main()
{
    int arr[3][3];
    cout << "enter the element of arrays " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Printing array " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
    printSum(arr,3,3);
cout<<endl;
    LargestRow (arr,3,3);
    

    return 0;
}