#include<iostream>
#include<vector>
using namespace std;

int countBinaryTree(int n){
	if(n<3) return n;
	vector<int> struct_memo(n+1, 0);
	vector<int> fact_memo(n+1, 0);
	
	struct_memo[0] = 1;
	struct_memo[1] = 1;
	fact_memo[0] = 1;
	fact_memo[1] = 1;
	
	for(int i=2; i<=n; i++){
		for(int j=0; j<i; j++){
			struct_memo[i] += struct_memo[j] * struct_memo[i-j-1];
		}
		fact_memo[i] = fact_memo[i-1]*i;
	}
	cout<<fact_memo[n]<<" "<<struct_memo[n]<<"   ";
	return fact_memo[n]*struct_memo[n];
}

int main(){
	cout<<countBinaryTree(3);
	
}
