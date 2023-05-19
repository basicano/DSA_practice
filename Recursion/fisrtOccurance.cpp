#include<iostream>
using namespace std;

int firstOccurance( int *arr, int target, int size, int first = 0 ){
	if(size == first){
		return -1;
	}
	else{
		if(arr[first] == target){
			return first;
		}
		else{
			return firstOccurance(arr, target, size,first+1);
		}
	}
}

int lastOccurance( int *arr, int target, int size){
	if(size == 0){
		return -1;
	}
	else{
		if(arr[size-1] == target){
			return size-1;
		}
		else{
			return lastOccurance(arr, target, size-1);
		}
	}
}

int freqOfElement(int *arr, int size, int target){
	if(size == 0){
		return 0;
	}
	else{
		if(arr[size-1] == target){
			return 1+ freqOfElement(arr, size-1, target);
		}
		else{
			return freqOfElement(arr, size-1, target);
		}
	}
}


int main(){
	int n;
	cout<<"Enter the size of the array : ";
	cin>>n;
	int *arr =new int[n];
	cout<<"Enter the elements of the array: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<"Enter the target element :";
	int target;
	cin>>target;
	
	cout<<"First occurance of target element in array is :"<<firstOccurance(arr,target,n);
	cout<<"\nLast occurance of target element in array is :"<<lastOccurance(arr,target,n);
	cout<<"\nNo. of occurances of target element in array is :"<<lastOccurance(arr,target,n);
}
