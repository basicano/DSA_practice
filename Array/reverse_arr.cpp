#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<" Enter the size of the array: ";
	cin>>n;
	cout<<" Enter the elements of the array: ";
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<" Entered Array is :";
	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
	
	cout<<"\n Reversed Array is :";
//	Approach 1
//	for(int i=n-1; i>=0; i--){
//		cout<<arr[i];
//	}

//	Approach 2
//	for(int i=0; i<n; i++){
//		cout<<arr[n-1-i];
//	}
	
//	Approach 3
	for(int i=0; i<n/2; i++){
		swap(arr[i],arr[n-1-i]);
	}
	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
	
	
	delete[] arr;
	return 0;
}
