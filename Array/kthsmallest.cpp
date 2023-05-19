#include<bits/stdc++.h>
#include<cmath>
using namespace std;

// KNOCKOUT TOURNAMENT METHOD

//int *win_path;
//
//int findKthSamllest(int *arr, int n, int k){
//	win_path = new int[log(n/2)];
//	int k_small;
//	
//	for(int)
//	while(--k){
//		findBattleWinner(arr, n, /* round 2 */, win_path);
//	}
//	
//}
//
//int findBattleWinner(int *contenders, int n, int round, win_path){
//	if(round>=log(n)){
//		return
//	}
//	else{
//		for(int i=0; i<n; i+=(round*2)){
//			if(a[i]<=a[i+round]){
//				// a[i] is winner
//			}
//			else{
//				// a[i] is loser
//			}
//		}
//	}
//}

int main(){
	cout<<" __ Program to find the Kth smallest element of the array __ \n";
	int n,k;
	cout<<"Enter the no. of elements in the array: ";
	cin>>n;
	
	int *a  = new int[n];
	cout<<"Enter the elements of the array: ";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}	
	cout<<"Enter the value of k: ";
	cin>>k;	
	
	sort(a,a+n);
	cout<<" The kth smallest element of the array is : "<< a[k-1];
	return 0;
}
