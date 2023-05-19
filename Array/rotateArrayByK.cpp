//Given an array nums and it's size n, rotate the array to the right by K steps, where K is non-negative.
#include<iostream>
using namespace std;

void rotateArray( int *arr, int n, int k){
	int copy = n-k;
	int *temp = new int[k];
	
	for(int i=0; i<k; i++){
		temp[i] = arr[n-k+i];
	}
	
	for(int i=n-k-1; i>=0; i--){
		arr[i+k] = arr[i];
	}
	
	for(int i=0; i<k; i++){
		arr[i] = temp[i];
	}
	return;
}

void print(int *arr, int n){
	for(int i=0; i<n; i++){
		cout<<arr[i];
	}
	return;
}

int main(){
	int n,k;
	cout<<" Enter the size of the array: ";
	cin>>n;
	int *arr = new int[n];
	cout<<" Enter the elements of the array: ";
	for(int i=0; i<n; i++){
		cin>> arr[i];
	}
	cout<<" Enter the value for k: ";
	cin>>k;
	cout<<" Entered array is: ";
	print(arr, n);
	rotateArray(arr,n,k);
	cout<<"\n Rotated array is: ";
	print(arr, n);
	return 0;	
	
}
