#include<iostream>
#include<vector>
using namespace std;

int countTrees(int N, vector<int> &dp){
	if(N==1) return 1;
	if(dp[N]!=1) return dp[N];

	for(int i=1; i<N; i++){
//		let i be the root
		dp[N] += countTrees(i-1, dp) * countTrees(N-i, dp);
	}			
	return dp[N];
}

int main(){
	int N = 4;
	vector<int> dp(N+1,1);
	cout<<countTrees(N,dp);
}
