#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int getFrequency(int* arr, int n, int target)
{
    int count=0;
    for(int i=0; i<n ; i++){
    	if(arr[i] == target) count++;
	}
	return count;
}

int main(){
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int el;
	cin>>el;
	cout<<getFrequency(a,n,el);
	return 0;
}
