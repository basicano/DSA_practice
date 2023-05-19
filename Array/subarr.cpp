#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of the array : ";
	cin>>n;
	int *arr = new int[n];
	
	cout<<"Enter the elements of the array : ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	cout<<"The subarrays are : "<<endl;	
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			for(int k=j;k<=i;k++){
				cout<<arr[k]<<" ";				
			}
			cout<<endl;
		}
	}
	return 0;
}
