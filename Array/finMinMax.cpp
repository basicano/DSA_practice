#include<bits/stdc++.h>
using namespace std;

pair<int,int> findMinMax(int A[], int size){
	pair<int, int> ans;
	
	if(A[0]<A[1]){
		ans.first = A[0];
		ans.second = A[1];
	}
	else{
		ans.second = A[0];
		ans.first = A[1];
	}
	
	for(int i=2; i<size-1; i+=2){
		if(A[i]>A[i+1]){
			if(A[i]>ans.second){
				ans.second = A[i];
			}
			else if(A[i+1]<ans.first){
				ans.first = A[i+1];
			}
		}
		else{
			if(A[i+1]>ans.second){
				ans.second = A[i+1];
			}
			else if(A[i]<ans.first){
				ans.first = A[i];
			}
		}
		
	}
	
	if(size%2==1){
		if(A[size-1]>ans.second){
			ans.second =A[size-1];
		}
		else if(A[size-1]<ans.first){
			ans.first = A[size-1];
		}
	}	
	return ans;
}

int main(){
	int n;
	cout<<" Enter the size of the array : ";
	cin>>n;
	int *arr = new int[n];
	
	cout<<" Enter the elements of the array : ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	pair<int,int> p;
	p = findMinMax(arr,n);
	cout<<"Min : "<<p.first<<"     Max: "<<p.second;
}
