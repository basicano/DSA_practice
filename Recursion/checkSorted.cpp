#include<iostream>
using namespace std;

bool checkSort( int *arr, int n){
	if(n<=1){
		return 1;
	}
	else{
		return (arr[n-1]>=arr[n-2]) && checkSort(arr,n-1);
	}
}

int main(){
	int n;
	cout<<" Enter the size of the array : ";
	cin>>n;
	int *arr = new int[n];
	cout<<" Enter the elements of the array : ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	
	
	if(checkSort(arr,n) ){
		cout<<" Array is sorted";
	}
	else{
		cout<<" Array is not sorted";
	}
	
	return 0;
}
