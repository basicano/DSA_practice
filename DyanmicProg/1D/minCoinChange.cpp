#include<iostream>
#include<vector>
using namespace std;

// RECURSIVE w/o DP
int minCoinChange(int M, vector<int> coins, int n){
//	cout<<"M="<<M;
//	for(int i=0; i<n; i++) cout<<"c"<<coins[i];
//	cout<<endl;
	if(M==0){
		return 0;
	}
	
	int ways = INT_MAX;
	for(int i=n-1; i>=0; i--){
		if(M-coins[i]>=0){
			ways = min(ways, minCoinChange(M-coins[i], coins, i+1) +1);
		}		 
	}
	return ways;
}

// TOP DOWN DP
int minCoinChangeTD(int M, vector<int> coins, int n, vector<int> &dp){
//	cout<<"M="<<M;
//	for(int i=0; i<n; i++) cout<<"c"<<coins[i];
//	cout<<endl;
	if(M==0){
		return 0;
	}
	if(dp[M]!=INT_MAX) return dp[M];
		
	for(int i=n-1; i>=0; i--){
		if(M-coins[i]>=0){
			dp[M] = min(dp[M], (minCoinChangeTD(M-coins[i], coins, i+1, dp)+1) );
		}		 
	}
	return dp[M];
}

// BOTTOM UP DP
int minCoinChangeBU(int M, vector<int> coins, int n){
	vector<int> dp(M+1,INT_MAX);
	dp[0] = 0;
	for(int j=0; j<=M; j++){
		for(int i=n-1; i>=0; i--){
			if(j-coins[i]>=0){
				dp[j] = min( dp[j], dp[j-coins[i]]+1 );
			}		 
		}
	}
	
//	for(int j=0; j<=M; j++) cout<<dp[j]<<" ";
	return dp[M];
}

int main(){
//	vector<int> coins {1,2,3};
	int M = 4;
////	22 or 13
//	cout<<endl<<minCoinChange(M, coins, 3);	
	
	vector<int> coins1 {1,3,7,10};
	M = 15;
//	7 7 1
	cout<<endl<<minCoinChange(M, coins1, 4);
	
	vector<int> dp(M+1,INT_MAX);
	cout<<endl<<minCoinChangeTD(M, coins1, 4, dp);
	cout<<endl<<minCoinChangeBU(M, coins1, 4);
	
	
}
