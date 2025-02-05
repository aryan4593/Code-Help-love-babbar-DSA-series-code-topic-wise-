#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& arr, int n, int k)
{
   int s=0, e =n-1;
   int mid =  s +(e-s)/1;

   while(s<e){
       if (arr[mid]>=arr[0]){
           s = mid +1;
       }
       else if (arr[mid]<= arr[e] ){
           e = mid;
       }
       else;

      

   }
 return s;
 }
