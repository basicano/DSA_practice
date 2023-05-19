#include<bits/stdc++.h>
using namespace std;

int findMissingNumber(int A[], int sizeOfArray) {
    int sum = 0;
    for(int i=0;i<sizeOfArray;i++){
        sum += A[i];
    }
    return (sizeOfArray+1)*(sizeOfArray+2)/2 - sum;
}

int main(){
   int n;
   cout<<"Enter the size of array : ";
   cin>>n;
   cout<<"Enter the elements of array: ";
   int *arr = new int[n];
   for(int i=0; i<n; i++){
   	    cin>>arr[i];
   }
   cout<<"The missing number is : "<<findMissingNumber(arr,n);
	delete [] arr;
	return 0;
}
