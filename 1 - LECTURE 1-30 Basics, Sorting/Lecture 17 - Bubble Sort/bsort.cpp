#include<iostream>
using namespace std;
#include<vector>

void bsort(vector<int> &v1,int size){
    for (int i =0;i<size;i++){
        // int temp = v1[i];
        for (int j=0;j<size;j++){
            if(v1[j]>v1[j+1]){
                swap(v1[j],v1[j+1]);
            }
            // else break;
        }
    }
}

int main (){
    vector<int> v1;
    v1={5,6,7,5,5,0,8,9};
    bsort(v1,v1.size());
    for(int i =0;i<v1.size();i++){
        cout<<v1[i]<<endl;
    }

}