#include<iostream>
#include<vector>
using namespace std;
#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	
	//to find (X^n)%m
	int res=1;
	while(n>0){
		if (n&1){//odd
		res = (1LL*(res)*(x)%m)%m;
		}
		x=(1LL*(x)%m*(x)%m)%m;
		n= n>>1;		//divide by 2
	}

	return res;
}
int main(){

    return 0 ;
}