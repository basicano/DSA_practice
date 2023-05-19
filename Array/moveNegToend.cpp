#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void moveNegativesToEnd(int *a, int n){
	int neg_ptr= n-1;
	for(int i=0; i<neg_ptr;){
		if(a[i]<0){
			swap(a[i], a[neg_ptr]);
			--neg_ptr;
		}
		else{
			i++;
		}
	}	
	return;
}

void print(int *arr, int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	return ;
}

int main(){
	int n;
	cout<<" Enter the size of the array  :";
	cin>>n;
	int *arr = new int[n];
	cout<<" Enter the elements of the array :";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<" Array after the negative integers are moved to the end: ";
	moveNegativesToEnd(arr, n);
	print(arr,n);
}
