#include<iostream>
using namespace std;
#include<vector>

void isort(vector<int> &v1,int size){
    for (int i =1 ; i<size ; i++){
        int temp = v1[i];
        int j=i-1;
        for(j;j>=0;j--){
            if (v1[j]>=temp){
                v1[j+1]=v1[j];
            }
            else break;
        }
        v1[j+1]=temp;
    }
}

int main (){
    vector<int> v1;
    v1={5,6,7,5,5,0,8,9};
    isort(v1,v1.size());
    for(int i =0;i<v1.size();i++){
        cout<<v1[i]<<endl;
    }

}