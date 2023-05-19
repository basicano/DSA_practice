#include<iostream>
using namespace std;

int C(int n, int k){
	if(n==k){
		return 1;
	}
	if(k==1){
		return n;
	}
	return C(n-1,k-1) + C(n-1,k);
}

int main(){
	int n,k;
	cout<<" Enter the value of n: ";
	cin>>n;
	cout<<" Enter the value of k: ";
	cin>>k;
	cout<<"Combination nCk: "<<C(n,k);
}

