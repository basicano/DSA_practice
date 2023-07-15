#include<iostream>
using namespace std;

int kLadder1(int n, int k){
//	base case
	if(n==0) return 1;
	
	int result = 0;
	for(int i=1; i<=k; i++){
		if(n-i>=0){
			result += kLadder1(n-i, k);
		}		
	}
	return result;
}

int kLadder2(int n, int k){
//	base case
	if(n==0) return 1;
	if(n<0) return 0;
	
	int result = 0;
	for(int i=1; i<=k; i++){
		result += kLadder2(n-i, k);		
	}
	return result;
}

int main(){
	cout<<kLadder1(6,3)<<endl;
	cout<<kLadder2(6,3);	
}
