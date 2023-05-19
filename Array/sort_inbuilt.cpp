#include<iostream>
#include<algorithm>
using namespace std;

void print (int*arr, int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int n=5,arr[5] ={3,5,2,4,1};
	cout<<" Array sorted in descending order: ";
	sort(arr, arr+n, greater<int>());		// sort [s,e)		greater<int> is the  comparator
	print(arr,n);
	return 0;
}
